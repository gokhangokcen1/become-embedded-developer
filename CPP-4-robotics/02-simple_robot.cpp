#include <iostream>
#include <string>

// bizi sürekli olarak bir şeylerin başına std:: yazmaktan kurtarıyor.
using namespace std; 

int main() {
    string robot_name = "AutomaticAddisonBot";
    int robot_battery = 80;

    cout << "Robot Name: " << robot_name << endl;
    cout << "Battery Level: " << robot_battery << endl;
    
    return 0;
}