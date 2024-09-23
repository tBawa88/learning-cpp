#include <cstdio>

struct Node {
    int data;
    Node() {
        data = 0;
    }
    Node(int data) {
        this->data = data;  // this is a pointer to the current object
    }
    int getData() { return this->data; }
};

/**
 * Member of Pointer operator ( -> )
 * 1. It dereferences the pointer
 * 2. Access the properties of the underlying obeject
 */

int main() {
    Node n1{100};
    Node n2{200};

    Node *ptr = &n1;

    printf("n1 data = %d\n", ptr->getData());
}
