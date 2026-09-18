#include <iostream>
#include <memory>

class Sensor {
    private:
        std::string name;
        double value;

    public: 
        Sensor(const std::string& name, double value) : name(name), value(value) {}

        void print_info() const {
            std::cout << "Sensor: " << name << ", Value: " << value << std::endl;
        }
};

int main() {
    std::unique_ptr<Sensor> sensor1 = std::make_unique<Sensor>("TemperatureSensor", 25.5);
    sensor1 -> print_info();

    std::shared_ptr<Sensor> sensor2 = std::make_shared<Sensor>("HumiditySensor", 60.0);
    sensor2 -> print_info();

    std::weak_ptr<Sensor> weak_sensor = sensor2;
    if (auto shared_sensor = weak_sensor.lock()) {
        shared_sensor -> print_info();
    }

    return 0;
}