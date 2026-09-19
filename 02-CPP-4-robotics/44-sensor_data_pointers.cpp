#include <iostream>

int main(){
    int sensor_value = 100;
    int* ptr = &sensor_value;

    std::cout << "Sensor Value: " << *ptr << std::endl;
    std::cout << "Memory Address: " << ptr << std::endl;

    *ptr = 200;
    std::cout << "Updated Sensor Value: " << sensor_value << std::endl;

    return 0;
}