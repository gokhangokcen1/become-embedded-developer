#include <iostream>
#include <eigen3/Eigen/Dense>

int main() {
    Eigen::Vector3d v(1,2,3); // Sütun matrisi oluşturuyor.
    std::cout << "v = "<< v.transpose() << std::endl; //

    return 0;
}