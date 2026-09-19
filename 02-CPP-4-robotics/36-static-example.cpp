#include <iostream>
#include <string>

class Robot {
    public: 
        Robot(std::string name, int x, int y){
            name_ = name;
            x_ = x;
            y_ = y;
            std::cout << "Robot " << name_ << " created at position (" << x_ << ", " << y_ << ")" << std::endl;
        }
    private:
        std::string name_;
        int x_;
        int y_;
};

int main() {
    Robot robot1("AutomaticAddisonBot1", 0, 0);
    Robot robot2("AutomaticAddisonBot2", 10, 20);

    return 0;
}