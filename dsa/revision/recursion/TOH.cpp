
#include <iostream>

void moveRods(int N, char from, char to, char temp) {
    if (N == 1)
        std::cout << "Move rod from " << from << " to " << to << std::endl;
    else {
        moveRods(N - 1, from, temp, to);
        moveRods(1, from, to, temp);
        moveRods(N - 1, temp, to, from);
    }
}
