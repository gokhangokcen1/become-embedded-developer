#include <iostream>

class Robot {
    public:
        int x, y;
        Robot(int x, int y) {
            this->x = x;
            this->y = y;
        }
        void print_coordinates() {
            std::cout << "Coordinates: (" 
            << this->x << ","
            << this->y << ")" <<std::endl;
        }
};

int main() {
    Robot my_robot(3,7);
    my_robot.print_coordinates();

    return 0;
}