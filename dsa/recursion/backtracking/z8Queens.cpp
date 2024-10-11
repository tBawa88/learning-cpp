#include <iostream>
#include <string>
#include <vector>
/**
 * Place 8 queens on a chess board such that no Queen is in line of sight of another Queen
 */
struct Board {
    Board(size_t size) : rows{size}, cols{size} {
        // allocate memory to an array of int pointers (rows)
        space = new int*[rows];

        // allocate memory to pointer in each element (cols)
        for (int i = 0; i < rows; i++) {
            space[i] = new int[cols];
        }
    }
    ~Board() {
        delete[] space;
    }
    // for the sake of overloading the outstream operator and be able to do this std::cout << board << std::endl;
    friend std::ostream& operator<<(std::ostream& os, Board& board);
    /**
     * Checks if it's safe to place a queen on given row, col
     */
    bool isSafe(int row, int col) {
    }

    /**
     * Place a Queen on a given row,col
     */
    void place(int row, int col) {
    }

    /**
     * Remove a Queen from a given row, col
     */
    void remove(int row, int cold) {
    }

   private:
    size_t rows;
    size_t cols;
    int** space;
};
std::ostream& operator<<(std::ostream& os, Board& board) {
    os << "The board is set";
    return os;
}
void solveQueens(Board& board);

// this helper will actuall perform all the recrusive tasks
bool queensHelper(Board& board, int column);
int main() {
    Board board{8};
    solveQueens(board);

    return 0;
}
void solveQueens(Board& board) {
    queensHelper(board, 0);  // we start at column 1, with Queen 1
}

/**
 * Each call to the recursive function needs to do "part" of the work
 * And we need to have enough parameters so that every call knows which part of the work it's responsible for
 * (like does it call the base case, or does it keep on recursing and perform some other operation)
 * The solveQueens() is not giving us enough parameters, because we don't have any information about how many queeens are left to place
 *
 * The "column" parameter represents a single queen , and it will tell us how many more columns we need to "set"
 */
bool queensHelper(Board& board, int column) {
    if (column == 7) {  // since it's zero indexed: 8th column has 7index
        std::cout << board << std::endl;
        return true;
    }

    // we need to place 1 queen in this column
    // for each possible row, check if the row, column combination is safe or not
    for (int row = 0; row < 8; row++) {
        // we only go down this path if the current combinatoin of row/column is safe
        if (board.isSafe(row, column)) {
            // choose
            board.place(row, column);
            //  explore
            bool finished = queensHelper(board, column + 1);
            if (finished) {
                return true;  // pass the previous function call the boolean value without breaking the chain of returns
            }
            //  unchoose
            board.remove(row, column);
        }
    }
    return false;  // this means the current path doesn't lead to the correct solution
    // meaning we've iterated over all 8 rows, and couldn't find a safe square to place the queen
}

/**
 * SOLUTION:
 * 1. Find the base case.
 * - which is reached when there are no more queens left to place
 * - meaning when column reaches 8, we have no more work to do(untill then keep trying for each column untill it's set)
 *
 * 2. Choosing in this case is placing the queen on the board by calling board.Place()
 * - before choosing , check if the current combination of row, column is safe or not
 *
 * 3. Exploring: calling the function with different params
 * - since this column is set, call the func for column + 1
 *
 * 4. UnChoosing - remove the current queen from row, column
 */

/**
 * STOPPING:
 *  - This code tries to find every possible solution
 *  - Our only goal is exit the function call as soon as we find one solution
 *  - The solution is found when the contoll reaches in the base case.
 *  - For that we can either set a global boolean flag which tells the recursion to stop
 *  - Or we make the queensHelper return a boolean and check on each call if the next call has returned true or not
 *
 *  - Making queensHelper return a boolean is a better alternative.
 *  - Now, every time we make a sub call inside the function , we need to store the returned value and make further calls based on it
 *
 *  - Returning false: IF, for a given column, we looped through all the rows and didn't find a safe square, our code will exit the loop
 *      in that case we return false to the previous call so that it """tries another row for the previous Queen"""
 *
 *  If we're unable to find a safe square fo current Queen, THAT MEANS THE PREVIOUS QUEEN WAS PLACED ON THE WRONG ROW
 *  So we return false make it try another row for prev queen
 */
