#include <iostream>
// TODO: implement with while and decrementing
int non_recursive_factorial(const int n) {
    if (n <= 1) {
        if (n < 0) {
            throw std::runtime_error("Factorial not defined for negative numbers");
        }
        return 1;
    }
    int product = 1;

    for (int i = 1; i<= n; i++) {
        product *= i;
    }
    return product;
}

int main() {
    std::cout << non_recursive_factorial(10) << std::endl;
    return 0;
}