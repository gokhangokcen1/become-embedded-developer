#include <iostream>
#include <thread>
#include <chrono>

void sensorTask(const std::string& sensor_name, int duration) {
    std::cout << "Sensor task started: " << sensor_name << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(duration));
    std::cout<< "Sensor task completed: " << sensor_name << std::endl;
}

void controlTask(const std::string& controller_name, int duration) {
    std::cout << "Control task started: " << controller_name << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(duration));
    std::cout<< "Control task completed: " << controller_name << std::endl;
}

int main() {
    std::cout << "Main thread started" << std::endl;

    std::thread sensor_thread1(sensorTask, "TemperatureSensor", 2);
    std::thread sensor_thread2(sensorTask, "HumiditySensor", 3);

    std::thread control_thread(controlTask, "MotionController", 4);

    sensor_thread1.join();
    sensor_thread2.join();
    control_thread.join();

    std::cout << "Main thread completed" << std::endl;

    return 0;
}