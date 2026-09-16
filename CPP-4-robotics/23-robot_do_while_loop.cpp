#include <iostream>

using namespace std;

int main() {
    int count = 0;

    do {
        cout << "Robot iteration: " << count << endl;
        count++;        
    } while (count < 3);

    return 0;
}