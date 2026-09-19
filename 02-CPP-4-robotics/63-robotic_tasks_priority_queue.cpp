#include <iostream>
#include <queue>
#include <vector>
#include <functional>

struct Task {
    int priority;
    std::string description;

    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
};

int main() {
    std::priority_queue<Task> tasks;

    tasks.push({2, "Navigate to charging station"});
    tasks.push({1, "Send sensor data"});
    tasks.push({3, "Emergenct stop"});

    while(!tasks.empty()) {
        Task task = tasks.top();
        tasks.pop();
        std::cout << "Executing task: " << task.description << std::endl;
    }

    return 0;
}