#include <iostream>

void increment_counter(); 

int main() {
    for (int i = 0; i < 5; i++){
        increment_counter();
    }
    return 0;
}

void increment_counter(){
    static int count = 0;
    count++;
    std::cout << "Counter: " << count << std::endl;

    // static int count = 0; yerine 
    // int count = 0; olsaydı her çağrıldığında 0'a eşitlenirdi. 
    // Bu sebeple çıktı: 
    // Counter: 1
    // Counter: 1
    // Counter: 1
    // Counter: 1
    // Counter: 1 olurdu. 
    // Statik bunun hafızası olmasını sağlıyor. 

}