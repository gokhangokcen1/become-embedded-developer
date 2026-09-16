#include <iostream>
#include <string>
// constructor/destructor + inheritance
// [TODO]:  Robot'tan miras alan `MobileRobot` sınıfı oluştur 
//          - Ek olarak wheel_count_ değişkeni olacak (name, battery, speed, wheel_count)
//          - `print_mobile_status()` methodu olacak



class Robot {
    private: 
        std::string name_;
        double battery_;
        double speed_; 
        double battery_threshold_ = 20;
        

    public:
        // Constructor 
        Robot (std::string name, double battery, double speed)
        : name_(name), battery_(battery), speed_(speed)
        {
        }

        void print_status(){
            std::cout << "\nMevcut Robot Durumu" << std::endl;
            std::cout << "Robot: " << name_ << std::endl;
            std::cout << "Battery Level: " << battery_ << std::endl;
            std::cout << "Speed: " << speed_ << std::endl;
            std::string battery_status_ = battery_ > battery_threshold_ ? "OK" : "LOW";
            std::cout << "Battery Status: " << battery_status_<< std::endl; 
            std::cout << std::endl;
        }

        void consume_battery(double amount){
            if (amount >= 0) {
            battery_ -= amount;
                if(battery_ <= 0){
                    battery_ = 0;
            }
            }else{
                std::cout << "Battery consumption cannot be negative." << std::endl;
            }}
        
        void set_speed(double speed){
            if (speed <=3 && speed >= 0){ 
                speed_ = speed;
            } else if (speed >= 3) {
                speed_ = 3;
            } else {
                std::cout << "Speed cannot be negative." << std::endl;
            }
            
        }

        double get_speed(){
            return speed_;
        }

        double get_battery(){
            return battery_;
        }

        void charge_battery(double amount){
            if (amount >= 0) {
                battery_ += amount;
                if (battery_ >= 100){
                    battery_ = 100;
                }
            }else {
                std::cout << "Charge amount cannot be negative." << std::endl;
            }
        }

        void move(double distance) {
            if (distance < 0) {
                std::cout << "Distance cannot be negative." << std::endl;
                return;
            }
            if (distance == 0) {
                std::cout << "Robot didn't move." << std::endl;
                return;
            }
            if (speed_ == 0) {
                std::cout << "Robot cannot move: speed is 0." << std::endl;
                return;
            }
            double time = distance / speed_;
            std::cout << "Robot moved " << distance << " meters." << std::endl;
            std::cout << "Required time: " << time << " second(s)." << std::endl;
        }
};

int main() {

    Robot gokhale_bot("GokhaleBot", 82, 1.25);
    gokhale_bot.print_status();
    gokhale_bot.set_speed(2.5);
    std::cout << "New Speed: " << gokhale_bot.get_speed() << std::endl; 
    gokhale_bot.move(10);
    gokhale_bot.consume_battery(65);
    gokhale_bot.print_status();
    gokhale_bot.charge_battery(30);
    gokhale_bot.print_status();
    gokhale_bot.set_speed(0);
    gokhale_bot.move(10);

    

    return 0;
}