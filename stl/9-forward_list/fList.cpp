/**
 * Implements a singly linked list under the hood
 */
#include <forward_list>
#include <iostream>

void walkList(std::forward_list<int>& l) {
    for (int n : l) {
        std::cout << n << std::endl;
    }
}

int main() {
    /**
     * We only have push_front() with the forward_list container class
     * So it's like a stack. You pop() from the same end you're pushing()
     */
    std::forward_list<int> list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.push_front(50);

    list.pop_front();
    walkList(list);
    return 0;
}
