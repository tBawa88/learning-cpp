#include <cstdio>
#include <iostream>
#include <queue>

void popAndPrint(std::queue<int>& q) {
    while (!q.empty()) {
        printf("%d\n", q.front());
        q.pop();
    }
}
/**
 * ADT methods are almost similar to stack the only difference is  the FIFO principle which is opposite of stack
 */
int main() {
    std::queue<int> que;
    que.push(10);
    que.push(20);
    que.push(30);
    que.push(40);
    que.push(50);

    popAndPrint(que);

    return 0;
}
