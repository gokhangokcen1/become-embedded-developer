#include <iostream>

template<typename T>

class Point {
    private:
        T x;
        T y;
    
    public: 
        Point(T x, T y) : x(x), y(y) {}

        T getX() const { return x; }
        T getY() const { return y; }

    void printPoint() const {
        std::cout << "(" << x << "," << y << ")" << std::endl;
    }
};

int main() {
    Point<int> int_point(5,10);
    Point<double> double_point(3.14, 2.71);

    std::cout << "Integer point: ";
    int_point.printPoint();

    std::cout << "Double point: ";
    double_point.printPoint();

    return 0;
}