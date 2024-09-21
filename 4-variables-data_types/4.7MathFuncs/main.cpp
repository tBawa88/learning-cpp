#include <cmath>
#include <iostream>

int main() {
    double weight{80.5};
    int limit{70};

    std::cout << "Max weight applicable in this case " << std::max(int(std::ceil(weight)), limit) << std::endl;

    signed int result = -123;  // abs() ignores sign and provides absolute value
    std::cout << "Absolute value of resul = " << std::abs(result) << std::endl;

    return 0;
}
