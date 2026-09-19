#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::stringstream ss;
    int motor_speed = 150;
    double battery_level = 12.5;

    ss << "Motor Speed: " << motor_speed << " RPM, Battery Level: " << battery_level << " Volts";

    std::string log_entry = ss.str();
    std::cout << "Log entry: " << log_entry << std::endl;
    
    return 0;
}