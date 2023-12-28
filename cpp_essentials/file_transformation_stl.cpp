#include <iostream>
#include <format>

template<typename T> 
struct Frac {
    T n; 
    T d;
};


// format specialization for the "Frac" type
template <typename T> 
struct std::formatter<Frac<T>>: std::formatter<unsigned> {
    template <typename Context> 
    auto format (const Frac<T>& f, Context& ctx) const {
        return format_to(ctx.out(), "{}/{}", f.n, f.d);
    }
};

 
template<typename ... Args> 
constexpr void print(const std::string_view str_fmt, Args&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}


int main() {
    return 0;
}
