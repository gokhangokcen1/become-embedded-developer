#include <iostream>

using namespace std;

int main() {
    int sensor_value = 527;
    double voltage; 

    voltage = sensor_value * 5.0 / 1023;
    cout << "Voltage (implicit casting): " << voltage << " V" << endl;

    voltage = (double)sensor_value * 5.0 / 1023;
    cout << "Voltage (C-style casting): " << voltage << " V" << endl;

    voltage = static_cast<double>(sensor_value) * 5.0 / 1023;
    cout << "Voltage (C++ style casting): " << voltage << " V" << endl;
    return 0;

}