#include <iostream>

int main() {
    double battery_level = 0.75;
    bool obstacle_detected = true;

    if(battery_level > 0.5 && !obstacle_detected) {
        std::cout << "Robot is moving forward." << std::endl;
    }else if (battery_level > 0.5 && obstacle_detected){
        std::cout << "Robot is avoiding the obstacle." << std::endl;
    }else{
        std::cout << "Robot is stopping due to low battery." << std::endl;
    }
    
    return 0;
}