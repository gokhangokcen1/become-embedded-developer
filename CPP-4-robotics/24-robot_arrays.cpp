#include <iostream>

using namespace std;

int main() {
    const int size = 5;
    int sensor_readings[size];

    // Initializing the array
    for(int i = 0; i < size; i++) {
        sensor_readings[i] = i * 10;
    }

    // Accessing array elements
    cout << "Sensor Readings: " << endl;
    for(int i = 0; i < size; i++) {
        cout << "Sensor " << i + 1 << ": " << sensor_readings[i] << endl;
    }

    return 0;
}