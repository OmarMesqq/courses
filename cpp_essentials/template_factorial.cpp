// Templates are useful when 
// a container of items is declared
// and the manipulation logic is type independent

#include <iostream>

template <typename T>
T non_recursive_factorial(T n) {
    if (n <= 1) {
        if (n < 0) {
            throw std::runtime_error("Factorial not defined for negative numbers");
        }
        return 1;
    }

    T prod = 1;
    while (n != 1) {
        prod *= n; 
        n--;
    }
    return prod;
}

int main() {
    std::cout << non_recursive_factorial(5) << std::endl;
    return 0;
}