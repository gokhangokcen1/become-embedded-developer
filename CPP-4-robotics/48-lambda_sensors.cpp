#include <iostream>
#include <vector>
#include <algorithm> // Include for std::sort

int main() {
    std::vector<int> sensor_readings = {90, 85, 60, 75, 100};

    std::cout << "Original readings: ";
    for (int reading : sensor_readings) {
        std::cout << reading << " ";
    }
    std::cout << std::endl;

    std::sort(sensor_readings.begin(), sensor_readings.end(), [](int a, int b){
        return a > b;
    });

    std::cout << "Sorted readings (desc): ";
    for (int reading : sensor_readings) {
        std::cout << reading << " ";
    }
    std::cout << std::endl;

    return 0;
}