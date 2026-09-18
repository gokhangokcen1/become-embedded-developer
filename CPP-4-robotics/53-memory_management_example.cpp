#include <iostream>
#include <cstdlib>

int main() {
    int *ptr = (int*) malloc(sizeof(int));
    if (ptr == nullptr) {
        std::cout << "Memory allocation failed" << std::endl;
        return -1;
    }

    *ptr = 5;
    std::cout << "Value at pointer: " << *ptr << std::endl;

    free(ptr);

    ptr = nullptr;

    return 0;
}