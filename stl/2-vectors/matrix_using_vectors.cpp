#include <iostream>
#include <vector>

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (auto row = matrix.begin(); row != matrix.end(); row++) {
        for (auto col = row->begin(); col != row->end(); col++) {  // even the -> operator is overloaded to make it look like a pointer
            std::cout << *col << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m, 0));

    printMatrix(matrix);

    return 0;
}
