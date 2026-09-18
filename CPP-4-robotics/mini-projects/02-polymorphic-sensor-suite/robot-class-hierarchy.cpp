#include <iostream>
#include <string>
#include <memory>
#include <random>
#include <iomanip>
#include <vector>
#include <map>
#include <stdexcept>

/**
 * @brief All sensors must have:
 *        - read(): returns a double
 *        - get_name(): returns a string
 *          const -> this function cannot modify the sensor object
 */
class Sensor {
public:
    virtual double read() = 0;
    virtual std::string get_name() const = 0;
    virtual ~Sensor() = default;
};

/**
 * @brief Distance sensor
 *        - get_name(): returns "Distance Sensor"
 *        - read():
 *            - Generate a random number between 0 and 99.
 *            - If the number is less than 5, simulate a sensor failure
 *              by throwing an exception.
 *            - Otherwise, generate a distance between 0.1 and 5.0 meters.
 */
class DistanceSensor : public Sensor {
public:
    std::string get_name() const override {
        return "Distance Sensor";
    }

    double read() override {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<int> error_chance(0, 99);

        if (error_chance(gen) < 5) {
            throw std::runtime_error(
                "Sensor disconnected: " + get_name()
            );
        }

        std::uniform_real_distribution<double> dis(0.1, 5.0);

        return dis(gen);
    }
};

/**
 * @brief Temperature sensor
 *        - get_name(): returns "Temperature Sensor"
 *        - read():
 *            - Generate a random number between 0 and 99.
 *            - If the number is less than 5, simulate a sensor failure
 *              by throwing an exception.
 *            - Otherwise, generate a distance between 15.0 and 35.0 celcius.
 */

class TemperatureSensor : public Sensor {
public:
    std::string get_name() const override {
        return "Temperature Sensor";
    }

    double read() override {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<int> error_chance(0, 99);

        if (error_chance(gen) < 5) {
            throw std::runtime_error(
                "Sensor disconnected: " + get_name()
            );
        }

        std::uniform_real_distribution<double> dis(15.0, 35.0);

        return dis(gen);
    }
};


/**
 * @brief IMU sensor
 *        - get_name(): returns "IMU Sensor"
 *        - read():
 *            - Generate a random number between 0 and 99.
 *            - If the number is less than 5, simulate a sensor failure
 *              by throwing an exception.
 *            - Otherwise, generate a distance between -180 and 180 degree.
 */
class ImuSensor : public Sensor {
public:
    std::string get_name() const override {
        return "IMU Sensor";
    }

    double read() override {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<int> error_chance(0, 99);

        if (error_chance(gen) < 5) {
            throw std::runtime_error(
                "Sensor disconnected: " + get_name()
            );
        }

        std::uniform_real_distribution<double> dis(-180.0, 180.0);

        return dis(gen);
    }
};


int main() {

    std::cout << std::fixed << std::setprecision(2);

    std::vector<std::unique_ptr<Sensor>> sensors;

    sensors.push_back(std::make_unique<TemperatureSensor>());
    sensors.push_back(std::make_unique<DistanceSensor>());
    sensors.push_back(std::make_unique<ImuSensor>());


    std::map<std::string, double> last_values;


    for (const auto& sensor : sensors) {
        try {
            double value = sensor->read();

            std::cout << sensor->get_name()
                      << ": "
                      << value
                      << std::endl;

            last_values[sensor->get_name()] = value;
        }
        catch (const std::runtime_error& e) {

            std::cout << "Sensör: "
                      << sensor->get_name()
                      << " bağlantısı koptu, atlanıyor"
                      << std::endl;
        }
    }


    std::cout << "\n--- Son Bilinen Değerler ---\n";

    for (const auto& [name, value] : last_values) {
        std::cout << name
                  << ": "
                  << value
                  << std::endl;
    }


    return 0;
}