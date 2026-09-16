#include <iostream>

bool sensor_triggered = false;

void check_sensor() {
    // Simulate sensor being triggered
    sensor_triggered = true;
}

int main() {
    std::cout << "Sensor initially triggered: " << (sensor_triggered ? "Yes" : "No") << std::endl;
    check_sensor();
    std::cout << "Sensor status after checking: " << (sensor_triggered ? "Yes" : "No") << std::endl; 
    
    return 0;
}