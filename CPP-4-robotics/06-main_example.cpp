#include <iostream>

int main(int argc, char *argv[]) {
    std::cout << "Welcome to Robotics Bootcamp!" << std::endl;

    // Print the command line arguments
    std::cout << "Arguments passed to the program:" << std::endl;
    
    for(int i = 0; i < argc; ++i) {
        std::cout << i << ":" << argv[i] <<std::endl;
    }


    // g++ main_example.cpp -o main_example
    // ./main_example arg1 "argument2" test123
    // OUTPUT
    // Welcome to Robotics Bootcamp!
    // Arguments passed to the program:
    // 0:./main_example
    // 1:arg1
    // 2:argument2
    // 3:test123

    return 0;
}