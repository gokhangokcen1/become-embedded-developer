#include <iostream>
#include <set>

int main() {
    std::set<int> unique_landmarks = {10, 20, 30, 20, 40, 30};
    std::cout << "Unique landmarks: ";
    for (const auto& landmark : unique_landmarks) {
        std::cout << landmark << " ";
    }
    std::cout << std::endl;

    std::multiset<std::string> repeated_commands = {"move", "rotate", "scan", "move", "grasp"};
    std::cout << "Repeated Commands: ";
    for (const auto& command: repeated_commands) {
        std::cout << command << " ";
    }
    std::cout << std::endl;

    return 0;
}