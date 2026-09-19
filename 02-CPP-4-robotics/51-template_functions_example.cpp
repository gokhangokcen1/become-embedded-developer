#include <iostream>

template <typename T>
T find_max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << "Max of 10 and 20 is: " << find_max<int>(10,20) << std::endl;
    std::cout << "Max of 5.5 and 2.1 is: " << find_max<double>(5.5,2.1) << std::endl;
}