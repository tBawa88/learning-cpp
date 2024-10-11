#include "queenUtils.h"

#include <iostream>

#define SIZE 8

void place_row(std::set<std::pair<int, int>>& unsafeBoxes, int row, int col, int** grid) {
    for (int i = 0; i < SIZE; i++) {
        auto box = std::make_pair(row, i);  // mark every column in that row as unsafe
        unsafeBoxes.insert(box);
        grid[row][i] = 420;
    }
}

void place_topRight(std::set<std::pair<int, int>>& unsafeBoxes, int row, int col, int** grid) {
    int r = row;
    int c = col;
    // top right - keep decrementing row until it hits zero and keep incrementing cols
    while (r > 0 && c < SIZE - 1) {
        r--;
        c++;
        auto box = std::make_pair(r, c);
        unsafeBoxes.insert(box);
        grid[r][c] = 420;
    }
}

void place_topLeft(std::set<std::pair<int, int>>& unsafeBoxes, int row, int col, int** grid) {
    int r = row;
    int c = col;
    // top left - keep decrementing both rown and col untill one of em hits 0
    while (r > 0 && c > 0) {
        r--;
        c--;
        auto box = std::make_pair(r, c);
        unsafeBoxes.insert(box);
        grid[r][c] = 420;
    }
}

void place_bottomRight(std::set<std::pair<int, int>>& unsafeBoxes, int row, int col, int** grid) {
    int r = row;
    int c = col;
    // bottom right - increment both rows and cols until one of em hits 7
    while (r < SIZE - 1 && c < SIZE - 1) {
        r++;
        c++;
        std::cout << "marking the diagonal [" << r << "," << c << "]\n";
        auto box = std::make_pair(r, c);
        unsafeBoxes.insert(box);
        grid[r][c] = 420;
    }
}

void place_bottomLeft(std::set<std::pair<int, int>>& unsafeBoxes, int row, int col, int** grid) {
    int r = row;
    int c = col;
    // bottom right - increment rows till it hits 7, keep decrementing cols until it hits 0
    while (r < SIZE - 1 && c > 0) {
        r++;
        c--;
        auto box = std::make_pair(r, c);
        unsafeBoxes.insert(box);
        grid[r][c] = 420;
    }
}
