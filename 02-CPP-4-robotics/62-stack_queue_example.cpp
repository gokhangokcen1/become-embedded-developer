#include <iostream>
#include <stack>
#include <queue>

int main() {
    std::stack<int> my_stack;
    my_stack.push(10);
    my_stack.push(20);
    my_stack.push(30);

    std::cout << "Top element of the stack: " << my_stack.top() << std::endl;
    my_stack.pop();

    std::cout << "Updated top element" << my_stack.top() << std::endl;

    std::queue<std::string> my_queue;
    my_queue.push("Sensor data");
    my_queue.push("Robot command");
    my_queue.push("Navigation goal");

    std::cout << "Front element of the queue: " << my_queue.front() << std::endl;
    my_queue.pop();

    std::cout << "Updated front element: " << my_queue.front() << std::endl;

    return 0;
}