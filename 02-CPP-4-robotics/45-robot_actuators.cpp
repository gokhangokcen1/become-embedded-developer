#include <iostream>

// Base class

class Actuator {
    public:
        virtual void activate () = 0;
};

// Derived class
class Motor : public Actuator {
    public:
        void activate() override {
            std::cout << "Motor is running." << std::endl;
        }
};

// Another derived class
class Servo : public Actuator {
    public:
        void activate() override {
            std::cout << "Servo adjusting position." << std::endl;
        }
};

// Function that demonstrates polymorphism 
void test_actuator(Actuator& actuator) {
    actuator.activate();
}

int main() {
    Motor motor;
    Servo servo;
    
    test_actuator(motor);
    test_actuator(servo);

    return 0;
}