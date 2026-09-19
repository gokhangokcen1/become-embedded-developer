#include <iostream>

class Robot {
    public: 
        virtual void move() {
            std::cout << "Robot is moving" << std::endl;
            }
};

class WheeledRobot : public Robot{
    public: 
        void move() override {
            std::cout << "Wheeled Robot is rolling" << std::endl;
            }
};

class LeggedRobot : public Robot {
    public: 
        void move() override{
            std::cout << "Legged Robot is walking" << std::endl;
            }
};


int main() {
    Robot* robot1 = new WheeledRobot();
    Robot* robot2 = new LeggedRobot();

    robot1->move();
    robot2->move();

    delete robot1; // new dediğimizde heap'ten yer tutuyor bu yüzden C'deki free gibi salmamız gerekiyor.
    delete robot2;


    
    return 0;
}