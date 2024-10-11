// Header file for Board class
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>

#ifndef BOARD_H  // this is a guard that prevents double inclusion. (if some other file is also including this and we include that file it creates problems)
#define BOARD_H

struct Board {
    Board(size_t size = 8);
    ~Board();
    void place(int row, int col);
    void remove(int row, int col);
    bool isSafe(int row, int col);
    std::string printBoard();

   private:
    std::unordered_map<int, std::set<std::pair<int, int>>> queenBoxes;
    int currentQueen;
    size_t rows;
    size_t cols;
    int **grid;
};

#endif  // BOARD_H
