#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> sensor_readings;
    sensor_readings["temperature"] = 25;
    sensor_readings["humidity"] = 60;
    sensor_readings["pressure"] = 1013;

    for(const auto& reading: sensor_readings) {
        std::cout << reading.first << ": " << reading.second << std::endl;
    }

    std::multimap<std::string, std::string> robot_commands;
    robot_commands.insert({"move", "forward"});
    robot_commands.insert({"move", "backward"});
    robot_commands.insert({"rotate", "left"});
    robot_commands.insert({"rotate", "right"});

    for (const auto& command: robot_commands){
        std::cout << command.first << ": " << command.second << std::endl;
    }

    return 0;
}