#include <iostream>
#include <chrono>
#include <thread> 

int main() {
    auto start_time = std::chrono::steady_clock::now();

    std::this_thread::sleep_for(std::chrono::seconds(2));

    auto end_time = std::chrono::steady_clock::now();

    std::chrono::duration<double> elapsed_seconds = end_time - start_time;

    std::cout << "Elapsed time: " << elapsed_seconds.count() << " seconds\n";

    return 0;
}