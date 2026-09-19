#include <iostream>

using namespace std;

// Definition of the DistanceSensor class
class DistanceSensor {
    private: 
        double range; // Maximum range of the sensor in meters

    public:
    // Constructor that initializes the sensor's range
    DistanceSensor(double max_range) : range(max_range) {}

    // Method to display the maximum range of the sensor
    void displayRange() { 
        cout << "Sensor maximum range: " << range << " meters" << endl;
    }

};      

int main() {
    DistanceSensor frontSensor(10.0);
    frontSensor.displayRange();

    DistanceSensor rearSensor(5.5);
    rearSensor.displayRange();

    return 0;
}