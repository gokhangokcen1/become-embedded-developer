#include <iostream>

class Robot {
    private: 
        int battery_level_; // Only accessible within the class

    protected: 
        int max_speed_; // Accessible within the class and derived class

    public: 
        Robot(int battery, int speed) {
            battery_level_ = battery;
            max_speed_ = speed;
        }

    void print_status(){
        std::cout << "Battery Level: " << battery_level_ << std::endl;
        std::cout << "Max Speed: " << max_speed_ << std::endl;
    }
};

int main() {
    Robot my_robot(75,10);
    my_robot.print_status();

    return 0;
}