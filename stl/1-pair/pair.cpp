#include <iostream>
#include <string>
/**
 * A simple struct that holds 2 values of arbitrary type
 */
int main() {
    std::pair<int, int> p1{1, 2};
    std::pair<int, char> p2 = std::make_pair(2, 'a');

    std::cout << "p1.1 = " << p1.first << " p1.2 = " << p1.second << std::endl;

    // you can also make a pair of pairs

    std::pair<std::string, std::pair<int, int> > student{"Jason", {25, 1999}};

    std::cout << "Student name = " << student.first << " Sutdent age = " << student.second.first << " Student DOB " << student.second.second << std::endl;

    return 0;
}
