#include <iostream>
#include <format>


int fac(int n) {
    if (n == 1) return 1;
    return n * fac(n-1);
}


bool is_prime(int n) {
    for (int i = n - 1; true; i--) {
        if (i == 1) return true;
        if (n % i == 0) return false; 
    }
    return false;
}

void prime_numbers() {

}

int main() {
    // std::cout << "Prime numbers under 100:\n";
    // prime_numbers();
    // bool x = is_prime(4);
    // std::cout << std::format("{}", x);
    return 0;
}
