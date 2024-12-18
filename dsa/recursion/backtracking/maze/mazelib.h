#include <string>

/**
 * File : mazelib.h
 * -------------------
 * This file defines the API required for solving maze
 */

#ifndef _mazelib_h
#define _mazelib_h

struct pointT {
    int x, y;
};

enum directionT {
    North,
    East,
    South,
    West
};
/*
 * Function: ReadMazeMap
 * Usage: ReadMazeMap(filename);
 * -----------------------------
 * This function reads in a map of the maze from the specified
 * file and stores it in private data structures maintained by
 * this module.
 */
void ReadMazeMap(std::string filename);

/*
 * Function: GetStartPosition
 * Usage: pt = GetStartPosition();
 * -------------------------------
 * This function returns a pointT indicating the coordinates of
 * the start square.
 */
pointT GetStartingPosition();

/*
 * Function: OutsideMaze
 * Usage: if (OutsideMaze(pt)) . . .
 * ---------------------------------
 * This function returns true if the specified point is outside
 * the boundary of the maze.
 */
bool OutsideMaze(pointT pt);

/*
 * Function: WallExists
 * Usage: if (WallExists(pt, dir)) . . .
 * -------------------------------------
 * This function returns true if there is a wall in the indicated
 * direction from the square at position pt.
 */
bool WallExists(pointT pt, directionT dir);

/*
* Functions: MarkSquare, UnmarkSquare, IsMarked
* Usage: MarkSquare(pt);
*
UnmarkSquare(pt);
*
if (IsMarked(pt)) . . .
* ------------------------------
* These functions mark, unmark, and test the status of the
* square specified by the coordinates pt.
*/
void MarkSquare(pointT pt);
void UnmarkSquare(pointT pt);
bool IsMarked(pointT pt);

#endif
