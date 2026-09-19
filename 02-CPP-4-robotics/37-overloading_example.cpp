#include <iostream>

void move_robot(int);
void move_robot(int, int);

int main() {
    move_robot(10);
    move_robot(5,7);

    return 0;
}


void move_robot(int distance){
    std::cout << "Moving robot forward by " << distance << " units." << std::endl;
}

void move_robot(int x, int y) {
    std::cout << "Moving robot to position " << "(" << x << "," << y << ")" << std::endl;
}