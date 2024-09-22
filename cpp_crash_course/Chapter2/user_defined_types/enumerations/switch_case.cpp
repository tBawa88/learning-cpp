#include <cstdio>
enum class Direction {
    North,  // by default starts with 0
    East,  // 1
    South,  // 2
    West  // 3
};

int main() {
    Direction d = Direction::North;

    switch (d) {
        case Direction::North: {
            printf("The direction is north\n`");
        } break;
        case Direction::East: {
            printf("This direction is east");
        } break;
        case Direction::South: {
            printf("This direction is south");
        } break;
        case Direction::West: {
            printf("This direction is west");
        } break;
        default: {
            printf("Invalid input\n");
        }
    }
    // The braces after 'case Direction::North :' are optional but are recommended since it can lead to unexpected behaviour sometimes
}
