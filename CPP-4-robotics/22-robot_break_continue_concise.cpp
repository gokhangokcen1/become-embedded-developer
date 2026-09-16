#include <iostream>

using namespace std;

int main() {
    int distance[] = {10, 20, 5, 30, 15};
    int max_distance = 25;

    for(int i = 0; i < 5; i++) {
        if(distance[i] > max_distance) {
            cout << "Distance exceeds maximum limit. Stopping robot." << endl;
            break;
        }
        if(distance[i] < 10) {
            cout << "Distance too short. Skipping iteration." << endl;
            continue;
        }
        cout << "Moving robot " << distance[i] << " units." << endl;
    }

    return 0;
}