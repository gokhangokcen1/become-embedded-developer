#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int random_int = std::rand();

    std::cout << "Random integer: " << random_int << std::endl;

    float random_float =
        static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);

    std::cout << "Random float between 0 and 1: "
              << random_float << std::endl;

    int min_value = 10;
    int max_value = 50;

    int random_range =
        min_value + (std::rand() % (max_value - min_value + 1));

    std::cout << "Random integer between "
              << min_value << " and " << max_value << ": "
              << random_range << std::endl;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<double> dis(0.0, 1.0);

    double random_double = dis(gen);

    std::cout << "Random double between 0 and 1 (Mersenne Twister): "
              << random_double << std::endl;

    return 0;
}