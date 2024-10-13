#include <cstdio>

void TOH(int disks, char src, char dest, char temp);
void movedisk(char from, char to);

int main() {
    TOH(3, 'A', 'C', 'B');
    return 0;
}

void TOH(int disks, char src, char dest, char temp) {
    if (disks == 1) {
        movedisk(src, dest);
    } else {
        // move n-1 disks from source to temporary tower, using dest as  a temp tower
        TOH(disks - 1, src, temp, dest);

        // move the base disk from source to destination
        TOH(1, src, dest, temp);

        // move the n-1 disks that are currently in temp tower to the final source, using src as the temp tower
        TOH(disks - 1, temp, dest, src);
    }
}

void movedisk(char from, char to) {
    printf("%c -> %c\n", from, to);
}
