#include "SinglyLL.h"

int main() {
    LinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);

    list.remove(3);
    list.printlist();

    return 0;
}
