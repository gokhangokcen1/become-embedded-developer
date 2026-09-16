#include <iostream>

using namespace std;

int main() {
    int robot_id = 42;
    int* ptr = &robot_id;

    cout << "Robot ID: " << robot_id << endl;
    cout << "Pointer Value: " << ptr << endl;
    cout << "Dereferenced Pointer: " << *ptr << endl;

    *ptr = 99;
    cout << "Updated Robot ID: " << robot_id << endl;

    return 0;
}