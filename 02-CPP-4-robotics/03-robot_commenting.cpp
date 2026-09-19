#include <iostream>

int main() {
    // Declare and initialize variables
    double speed = 0.5; //speed of the robot in meters per second
    double time = 10.0; // Time traveled in seconds

    /* Calculate the distance traveled 
    distance = speed * time
    */

    double distance = speed * time;

    // Print the result
    std::cout << "The robot traveled " << distance << " meters." << std::endl;
}