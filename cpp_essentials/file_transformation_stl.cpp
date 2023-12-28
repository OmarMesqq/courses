#include <cctype>
#include <format>
#include <fstream>
#include <iostream>

template <typename T>
struct Frac {
    T n;
    T d;
};

// format specialization for the "Frac" type
template <typename T>
struct std::formatter<Frac<T>> : std::formatter<unsigned> {
    template <typename Context>
    auto format(const Frac<T>& f, Context& ctx) const {
        return format_to(ctx.out(), "{}/{}", f.n, f.d);
    }
};

template <typename... Args>
constexpr void print(const std::string_view str_fmt, Args&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(),
          stdout);
};

int main() {
    static const char* filename{"items.txt"};
    static char fileBuffer[350];    // a little more than ammount of chars in file

    int tabCounter{1};
    bool nextNewSku{true};

    {
        // scope for reading file by chunks (each line)
        std::ifstream infile(filename);
        while (infile.good()) {
            std::string parsedItems{};
            infile.getline(fileBuffer, sizeof(fileBuffer));

            for (const auto& c : fileBuffer) {
                if (isdigit(c)) {
                    if (nextNewSku) {
                        parsedItems += std::string("\nsku: ") + c;
                        nextNewSku = false;
                    } else {
                        parsedItems += c;
                    }
                } else if (c == '\t') {
                    switch (tabCounter) {
                        case 1:
                            parsedItems += std::string(", name: ");
                            tabCounter++;
                            break;
                        case 2:
                            parsedItems += std::string(", desc: ");
                            tabCounter = 1;
                            break;
                        default:
                            break;
                    }
                } else {
                    parsedItems += c;
                };
            }
            nextNewSku = true;
            print("{}", parsedItems);
        }
    }
    return 0;
}
