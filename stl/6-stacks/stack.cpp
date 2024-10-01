#include <cstdio>
#include <iostream>
#include <stack>

void popAndPrint(std::stack<int>& s) {
    while (!s.empty()) {
        printf("%d\n", s.top());
        s.pop();
    }  // one thing to keep in mind, stack.pop() in c++ doesn't return the elemnt it just pops it
    // to get the topmost element, use stack.top()
}

/**
 * Follows the FILO principle
 */

int main() {
    std::stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    popAndPrint(stack);

    // swapping one stack with another
    std::stack<int> stack2;
    stack2.push(99);
    stack2.push(100);
    stack2.push(101);
    stack2.push(98);

    stack.swap(stack2);
    // stack = stack2;  // this is a copy assignment not a move assignment
    popAndPrint(stack);
    popAndPrint(stack2);

    return 0;
}
