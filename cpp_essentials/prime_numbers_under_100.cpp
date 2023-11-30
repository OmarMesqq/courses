#include <iostream>
#include <format>

bool is_prime(const int n, int i) {
    if (i <= 1) {
        if (i == 1) return true;
        else return false;
    }
    if (n % i == 0) return false;
    return is_prime(n, i - 1);
}

void prime_numbers() {
    for (int i = 0; i <= 100; i++) {
        if (is_prime(i, i - 1)) {
            std::cout << std::format("{}\n", i);
        }
    }
}

int main() {
    prime_numbers();
    return 0;
}
