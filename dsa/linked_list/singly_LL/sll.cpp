#include <cstdio>
#include <iostream>
#include <stdexcept>

template <typename T>
struct Node {
    Node* next;
    T val;

    Node() = default;
    Node(T val) noexcept {
        this->val = val;
        this->next = nullptr;
    }

    Node(T val, Node* next) noexcept {
        this->val = val;
        this->next = next;
    }
    ~Node() { printf("Node deleted\n"); }
};

template <typename T>
struct LinkedList {
    Node<T>* head;
    int size;

    LinkedList() : head{nullptr} {};

    LinkedList* push_back(T val) {
        Node<T>* newnode = new Node{val};
        if (!head) {
            head = newnode;
            ++size;
            return this;
        }

        Node<T>* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newnode;
        ++size;
        return this;
    }
    ~LinkedList() {
        // release all the nodes right
        Node<T>* node = head;
        while (node) {
            Node<T>* prev = node;
            node = node->next;
            delete prev;
        }
    }

    T pop_back() {
        if (!head) {
            throw std::runtime_error{"List is empty"};
        }
        Node<T>** curr = &head;

        // reach the last node and directly remove it
        while ((*curr)->next) {
            curr = &(*curr)->next;
        }
        T val = (*curr)->val;
        delete (*curr);
        *curr = nullptr;
        --size;
        return val;
    }

    void printlist() {
        Node<T>* node = head;
        while (node) {
            std::cout << node->val << std::endl;
            node = node->next;
        }
    }
};

int main() {
    LinkedList<int> list;
    list.push_back(10)->push_back(20)->push_back(30)->push_back(40);
    list.printlist();

    std::cout << list.pop_back() << " = Popped node" << std::endl;
    std::cout << list.pop_back() << " = Popped node" << std::endl;
    std::cout << list.pop_back() << " = Popped node" << std::endl;
    std::cout << list.pop_back() << " = Popped node" << std::endl;
    list.printlist();

    return 0;
}
