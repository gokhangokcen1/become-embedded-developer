#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double angle = 45.0;
    double radians = angle * M_PI / 180.0;

    double sine = sin(radians);
    double cosine = cos(radians);

    cout << "Sine: " << sine << endl;
    cout << "Cosine: " << cosine << endl;


}