#include <iostream>

class RobotController {
    public: 
        RobotController() {

        }
        ~RobotController() {
            std::cout << "Robot controller shutting down" << std::endl; // Cleaning up resources
        }

        void control_robot() {
            std::cout << "Controlling robot..." << std::endl;
        }
};

int main() {
    RobotController controller;
    controller.control_robot();
    return 0;
}