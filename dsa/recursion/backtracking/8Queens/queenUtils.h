// for util functions being used inside Board struct functions
#include <set>

#ifndef QUEEN_UTILS_H
#define QUEEN_UTILS_H

void place_row(std::set<std::pair<int, int>>& unsafeBoxes, int row, int col, int** grid);
void place_topRight(std::set<std::pair<int, int>>& unsafeBoxes, int row, int col, int** grid);
void place_topLeft(std::set<std::pair<int, int>>& unsafeBoxes, int row, int col, int** grid);
void place_bottomRight(std::set<std::pair<int, int>>& unsafeBoxes, int row, int col, int** grid);
void place_bottomLeft(std::set<std::pair<int, int>>& unsafeBoxes, int row, int col, int** grid);

#endif
