#include <iostream>
#include <cctype>

using namespace std;

int main() {
    char command = 'f';

    // Checking character properties
    if(islower(command)) {
        cout << "Command is lowercase" << endl;
    }

    char uppercase_command = toupper(command);
    cout << "Uppercase Command: " << uppercase_command << endl;

    // Checking character equality
    if (command = 'f') {
        cout << "Command is 'f'" << endl;
    }

    return 0;

}