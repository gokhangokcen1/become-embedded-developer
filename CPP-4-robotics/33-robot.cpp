#include "33-robot.hpp"
#include <iostream>

void Robot::greet(){
    std::cout << "Hello, I am a robot." << std::endl;
}

int main() {
    Robot my_robot;
    my_robot.greet();
    return 0;
}