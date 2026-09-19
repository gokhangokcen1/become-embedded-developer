#include <iostream>
#include <cmath>

using namespace std;

// Function declaration
double calculate_distance(double x1, double y1, double x2, double y2);

int main() {
    double distance = calculate_distance(0, 0, 3, 4);
    cout << "Distance: " << distance << endl;
    return 0;
}

// Function definition
double calculate_distance(double x1, double y1, double x2, double y2){
    double dx = x2 - x1;
    double dy = y2 - y1;
    double distance = sqrt (dx * dx + dy * dy);
    return distance;
}