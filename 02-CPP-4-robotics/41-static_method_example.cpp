#include <iostream>
#include <cmath>

class RobotUtils {
    public: 
        static double calculate_distance(double x1, double y1, double x2, double y2) {
            double dx = x2- x1;
            double dy = y2 - y1;
            return std::sqrt(dx * dx + dy * dy);
        }
};

int main() {
    double robot1_x = 0.0, robot1_y = 0.0;
    double robot2_x = 3.0, robot2_y = 4.0;

    double distance = RobotUtils::calculate_distance(robot1_x, robot1_y, robot2_x, robot2_y);
    std::cout << "Distance between robots: " << distance << std::endl;
}