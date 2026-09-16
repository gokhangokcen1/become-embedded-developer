#include <iostream>
#include <string>

using namespace std;

int main() {
    string robot_name = "AutomaticAddisonBot";

    cout << "Robot Name: " << robot_name << endl;
    cout << "First Character: " << robot_name[0] << endl;

    robot_name[8] = '-';
    cout << "Modified Robot Name: " << robot_name << endl;

    string model = "X100";
    string full_name = robot_name + " " + model;
    cout << "Full Name: " << full_name << endl;

    return 0;
}