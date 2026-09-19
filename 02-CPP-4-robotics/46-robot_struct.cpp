#include <iostream>
#include <string>

struct RobotSpec {
    std::string model;
    int max_speed;
    double weight;
};

void print_robot_spec(const RobotSpec& spec) {
    std::cout << "Model: " << spec.model << std::endl;
    std::cout << "Max Speed: " << spec.max_speed << " m/s" << std::endl;
    std::cout << "Weight: " << spec.weight << " kg" << std::endl;
}

int main() {
    RobotSpec robot = {"MobileBot", 5, 10.5};
    print_robot_spec(robot);
    return 0;
}
