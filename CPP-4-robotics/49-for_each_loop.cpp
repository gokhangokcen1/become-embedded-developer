#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> distances = {5, 10, 3, 7, 9};

    std::cout << "Original distances: ";
    for (int distance : distances) {
        std::cout << distance << " ";
    }
    std::cout << std::endl;

    std::for_each(distances.begin(), distances.end(), [](int &d){
        d+=1; // Increment each element by 1
    });

    std::cout << "Updated distances: ";
    for (int distance : distances) {
        std::cout << distance <<  " ";
    }
    std::cout << std::endl;

    return 0;

}