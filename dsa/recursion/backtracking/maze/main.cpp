#include <string>

#include "mazelib.h"

/**
 * Function: AdjacentPoint(pt, dir)
 * ----------------------------------
 * Moves the given point one square in the given direction
 */
pointT AdjacentPoint(pointT pt, directionT dir) {
    pointT newPt = pt;
    switch (dir) {
        case North:
            newPt.y++;
            break;
        case East:
            newPt.x++;
            break;
        case South:
            newPt.y--;
            break;
        case West:
            newPt.x--;
            break;
    }
    return newPt;
}

bool SolveMaze(pointT pt) {
    if (OutsideMaze(pt))
        return true;
    if (IsMarked(pt))
        return false;

    MarkSquare(pt);
    for (int i = 0; i < 4; i++) {
        directionT dir = directionT(i);
        if (!WallExists(pt, dir)) {
            // CHOOSING and EXPLORING
            // if the square in this direction is not blocked, then move to that square and explore
            if (SolveMaze(AdjacentPoint(pt, dir))) {
                return true;
            }
        }
    }
    // UNCHOOSING
    UnmarkSquare(pt);
    return false;
}

int main() {
    ReadMazeMap("filename");
    if (SolveMaze(GetStartingPosition())) {
        printf("The marked squares show the path out of the maze\n");
    } else {
        printf("The maze is unsolvable\n");
    }

    return 0;
}
