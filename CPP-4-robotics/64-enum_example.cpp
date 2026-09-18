#include <iostream>

enum class RobotState {
    IDLE, 
    MOVING,
    GRASPING,
    ERROR
};

void print_robot_state(RobotState state) {
    switch (state) {
        case RobotState::IDLE:
            std::cout << "Robot is idle." << std::endl;
            break;
        case RobotState::MOVING:
            std::cout << "Robot is moving." << std::endl;
            break;
        case RobotState::GRASPING:
            std::cout << "Robot is grasping an object." << std::endl;
            break;
        case RobotState::ERROR:
            std::cout << "Robot encountered an error." << std::endl;
            break;
    }
}

int main() {
    RobotState current_state = RobotState::IDLE;
    print_robot_state(current_state);

    current_state = RobotState::MOVING;
    print_robot_state(current_state);

    return 0;
}