#include <cstdio>
class Point2 {
    int x, y;
};

struct Point {
    int x, y;
    Point2 p;
    Point(int x, int y) : x{x}, y{y} {}
};

Point transpose(Point p) {
    int temp = p.x;
    p.x = p.y;
    p.y = temp;
    return p;
}

int add_one_to(int x) {
    return ++x;
}

int main() {
    auto var = 10;
    auto result = add_one_to(var);
    printf("var = %d, result = %d", var, result);

    Point p{10, 20};
    Point q = transpose(p);
    // passing a point to transpose is making a copy of it and the original structure is un-affected
    // But this approach is dangerous in case of Fully featured classes with pointers a their members

    return 0;
}
