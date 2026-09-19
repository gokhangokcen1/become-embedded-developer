#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> motor_speeds;

    // Adding elements to the vector
    motor_speeds.push_back(100);
    motor_speeds.push_back(200);
    motor_speeds.push_back(150);

    // Accessing vector elements
    cout << "Motor Speeds" << endl;
    for (int i = 0; i < motor_speeds.size(); i++) {
        cout << "Motor " << i + 1 << ": " << motor_speeds[i] << endl;
    }
    return 0;
}
