#include "Board.h"

#include <iostream>
#include <set>
#include <string>
#include <unordered_map>

#include "queenUtils.h"

Board::Board(size_t size) : rows{size}, cols{size}, currentQueen{0} {
    grid = new int*[rows];
    for (int i = 0; i < size; i++)
        grid[i] = new int[cols];
}

Board::~Board() {
    delete[] grid;
}
void Board ::place(int row, int col) {
    std::set<std::pair<int, int>> unsafeBoxes;

    // place all boxes in the current row, and diagonals into the set
    place_row(unsafeBoxes, row, col, this->grid);
    place_topRight(unsafeBoxes, row, col, this->grid);
    place_topLeft(unsafeBoxes, row, col, this->grid);
    place_bottomRight(unsafeBoxes, row, col, this->grid);
    place_bottomLeft(unsafeBoxes, row, col, this->grid);

    // add this set to the map
    this->queenBoxes[currentQueen++] = unsafeBoxes;
    // also mark this box inside the grid
    this->grid[row][col] = 69;
}

/**
 * This removes the previous queen, hence freeing all it's squares
 */
void Board::remove(int row, int col) {
    --this->currentQueen;  // since the current queen couldn't be placed

    // before removing mark all grid boxes as safe
    auto unsafeBoxes = this->queenBoxes[currentQueen];
    for (auto box : unsafeBoxes) {
        std::cout << "releasing box [" << box.first << "," << box.second << "]\n";
        this->grid[box.first][box.second] = 0;
    }

    this->queenBoxes.erase(currentQueen);  // Remove previous queens entry from the map
    this->grid[row][col] = 0;  // update the grid box value
}

/**
 * Checks if the given square is present it any queen's unsafe boxes map
 */
bool Board::isSafe(int row, int col) {
    auto box = std::make_pair(row, col);
    // iterate over the entire map, then check if the map exists it set of any key
    for (auto it : this->queenBoxes) {
        auto unsafeSet = it.second;
        if (unsafeSet.contains(box)) {
            std::cout << "UNSAFE to place " << row << " " << col << std::endl;
            return false;
        }
    }
    return true;
}

std::string Board::printBoard() {
    std::string boardState;
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            if (this->grid[i][j] == 69)
                boardState += " Q ";
            // else if (this->grid[i][j] == 420)
            //     boardState += " X ";
            else
                boardState += " - ";
        }
        boardState += "\n\n";
    }

    return boardState;
}
