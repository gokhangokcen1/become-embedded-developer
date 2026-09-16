#include <iostream>
#include <stdexcept>

double divide(double a, double b);

int main() {
    try {
        double result = divide(10, 0);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

double divide(double a, double b) {
    if (b==0){
        throw std::runtime_error("Division by zero");
    }
    return a / b;
}