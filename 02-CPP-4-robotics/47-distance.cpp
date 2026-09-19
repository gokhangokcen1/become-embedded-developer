#include <iostream>

class Distance {
    public: 
        int meters;
        Distance (int m = 0) : meters (m) {}

        Distance operator+(const Distance& other) const {
            return Distance(meters + other.meters);
        }

};

int main() {
    Distance d1(5);
    Distance d2(10);
    Distance sum = d1 + d2;
    std::cout << "d1 = " << d1.meters << " meters" << std::endl;
    std::cout << "d2 = " << d2.meters << " meters" << std::endl;
    std::cout << "sum = " << sum.meters << " meters" << std::endl;

    return 0;
}