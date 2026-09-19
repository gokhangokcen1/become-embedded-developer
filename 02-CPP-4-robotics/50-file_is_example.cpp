#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "robot_data.txt";
    std::ofstream output_file(filename);

    if (output_file.is_open()) {
        output_file << "Sensor1: 10.5\n";
        output_file << "Sensor2: 20.7\n";
        output_file << "Sensor3: 15.2\n";
        output_file.close();
        std::cout << "Data written to a file: " << filename << std::endl;

    } else {
        std::cout << "Unable to open file for writing." << std::endl;
    }

    std::ifstream input_file(filename);
    std::string line;

    if (input_file.is_open()) {
        while(std::getline(input_file, line)) {
            std::cout << line << std::endl;
        }
        input_file.close();
    } else {
        std::cout << "Unable to open file for reading." << std::endl;
    }
    
    return 0;
}
