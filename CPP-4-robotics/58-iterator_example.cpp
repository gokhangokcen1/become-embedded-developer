#include <iostream>
#include <vector>

int main() {
    std::vector<int> sensor_data = {10, 20, 30, 40, 50};

    for (auto it = sensor_data.begin(); it != sensor_data.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for (auto it = sensor_data.begin(); it != sensor_data.end(); ++it) {
        *it *= 2;
    }

    for (const auto& value : sensor_data) {
        std::cout << value << " ";
    }

    std::cout << std::endl;

    return 0;

}