#include <iostream>
#include <string>
#include <iomanip>

int main() {
    int encoder_ticks = 720;

    double battery_voltage = 12.7;

    char motor_direction = 'F'; 

    bool is_sensor_active = true;

    std::string robot_name = "AutomaticAddisonBot";

    std::cout << "Robot Name: " << robot_name << std::endl;
    std::cout << "Encoder Ticks: " << encoder_ticks << std::endl;
    std::cout << "Battery Voltage: " << battery_voltage << std::endl;
    std::cout << "Motor Direction: " << motor_direction << std::endl;
    std::cout << "Sensor Active: " << (is_sensor_active ? "Yes" : "No") << std::endl;

    battery_voltage = 12.734234234;

    std::cout << "Default precision: " << battery_voltage << std::endl;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Precision set to 2 decimal places: " << battery_voltage << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Precision set to 5 decimal places: " << battery_voltage << std::endl;


    return 0;
}