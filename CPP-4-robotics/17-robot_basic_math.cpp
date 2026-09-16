#include <iostream>

int main() {
    int motor_speed = 100; // Base speed
    int speed_increment = 20; // Speed adjustment

    // Addition
    int increased_speed = motor_speed + speed_increment;

    // Substraction
    int decreased_speed = motor_speed - speed_increment;
    
    // Multiplication
    int double_speed = motor_speed * 2;
    
    // Division
    int half_speed = motor_speed / 2;

    // Modulus
    int remainder = motor_speed % 30;

    // Output results
    std::cout << "Original speed: " << motor_speed << std::endl;
    std::cout << "Increased speed: " << increased_speed << std::endl;
    std::cout << "Decreased speed: " << decreased_speed << std::endl;
    std::cout << "Double speed: " << double_speed << std::endl;
    std::cout << "Half speed: " << half_speed << std::endl;
    std::cout << "Remainder: " << remainder << std::endl;

    return 0;
}