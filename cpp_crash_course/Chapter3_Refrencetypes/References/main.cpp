#include <iostream>

/**
 * References are more safer versions of pointers
 * Refs cannot be assigned to null(easily) , and they cannot be re-assigned
 */
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

// this function expects a reference to the node type
void update_data(Node& node, int newData) {
    node.data = newData;
}

int main() {
    Node n{23};
    printf("Old data = %d\n", n.data);

    update_data(n, 55);  // a reference is passed to the function implicitly
    // any changes made to the reference are reflected in the original object

    printf("Updated data = %d\n", n.data);

    // References cannot be reseated
    int original = 100;
    int& duplicate = original;
    printf("Original value = %d\n", original);
    printf("Original ref = %d\n", duplicate);

    int newValue = 200;
    duplicate = newValue;  // we're not updating the reference value here, duplicate is still pointing to original
    // They all get updated to 200, making a reference point to something else also changes it's original reference
    printf("Original value = %d\n", original);
    printf("New value = %d\n", newValue);
    printf("Original ref = %d ----------\n", duplicate);

    int thirdvalue = 300;
    duplicate = thirdvalue;

    // This time the newValue remains the same, but original and duplicate gets updated to thridvalue
    //  this is due to the fact that once a value is stored in a Reference type, it keep pointing to it
    printf("Original value = %d\n", original);
    printf("Original ref = %d\n", duplicate);
    printf("New value = %d\n", newValue);
    printf("Third value = %d\n", thirdvalue);

}
