#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <ctime>
#include <vector>
#include <iomanip>
#include <thread>
#include <fstream>

/**
 * @brief Sensor gave 4 information and we keep these variable in a struct: sensor_name, value, unit, timestamps.
 * 
 */
struct SensorReading {
    std::string sensor_name;
    double value;
    std::string unit;
    double timestamp_seconds;
};


/**
 * @brief Generating fake sensor datas. 
 * 
 * @param sensor_name 
 * @return SensorReading 
 */
SensorReading generate_fake_reading(const std::string& sensor_name) {
    SensorReading reading;
    reading.sensor_name = sensor_name;
    reading.timestamp_seconds = static_cast<double>(std::time(nullptr));
    
    std::random_device rd;
    std::mt19937 gen(rd());

    if (sensor_name == "temperature") {
        std::uniform_real_distribution<double> dis(18.0, 30.0);
        reading.value = dis(gen);
        reading.unit = "C";
    }

    if (sensor_name == "battery") {
        std::uniform_real_distribution<double> dis(0.0, 100.0);
        reading.value = dis(gen);
        reading.unit = "%";
    }

    if (sensor_name == "distance") {
        std::uniform_real_distribution<double> dis(0.1, 5.0);
        reading.value = dis(gen);
        reading.unit = "m";
    }

    return reading;
}

/**
 * @brief Write all the fake sensor datas to sensor_logs.txt : sensor_name value unit timestamp_seconds
 * 
 * @param log 
 */
void writeLog(const std::vector<SensorReading>& log) {
    std::ofstream output_file("sensor_logs.txt");
    if (!output_file.is_open()) {
        std::cerr << "Dosya acilamadi!" << std::endl;
        return;
    }
    for (const auto& reading : log) {
        output_file << reading.sensor_name << " " << reading.value << " "
                    << reading.unit << " " << reading.timestamp_seconds << std::endl;
    }
    output_file.close();
}


int main() {
    
    std::vector<SensorReading> log;

    for (int i = 0; i < 10; i++) {
        SensorReading temp_reading = generate_fake_reading("temperature");
        SensorReading batt_reading = generate_fake_reading("battery");
        SensorReading dist_reading = generate_fake_reading("distance");

        log.push_back(temp_reading);
        log.push_back(batt_reading);
        log.push_back(dist_reading);

        std::cout << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << temp_reading.sensor_name << ": " << temp_reading.value << " " << temp_reading.unit << std::endl;
        std::cout << batt_reading.sensor_name << ": " << batt_reading.value << " " << batt_reading.unit << std::endl;
        std::cout << dist_reading.sensor_name << ": " << dist_reading.value << " " << dist_reading.unit << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        std::cout << "-----------------------" << std::endl;
    }

    writeLog(log);



    return 0;
}