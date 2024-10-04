#include <iostream>
#include <stdexcept>

template <typename T>
struct Node {
    T val;
    Node* next;
    Node* prev;

    Node(T val) : val{val} {
        next = nullptr;
        prev = nullptr;
    }
    ~Node() {
        std::cout << "node deleted" << std::endl;
    }
};

template <typename T>
struct DLinkedList {
    Node<T>* head;
    Node<T>* tail;
    int size;

    DLinkedList() : head{nullptr}, tail{nullptr}, size{0} {}
    ~DLinkedList() {
        Node<T>* node = head;
        while (node) {
            Node<T>* temp = node;
            node = node->next;
            delete temp;
        }
    }

    DLinkedList* push_back(T val) {
        Node<T>* newnode = new Node{val};
        if (!head) {
            head = newnode;
            tail = newnode;
            ++size;
            return this;
        }

        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
        ++size;
        return this;
    }

    DLinkedList* push_front(T val) {
        Node<T>* newnode = new Node{val};
        if (!head) {
            head = newnode;
            tail = newnode;
            ++size;
            return this;
        }

        head->prev = newnode;
        newnode->next = head;
        head = newnode;
        ++size;
        return this;
    }

    T pop_back() {
        if (!head) {
            throw std::runtime_error{"pop_back: list is empty"};
        }

        Node<T>* temp = tail;
        T val = tail->val;
        tail = tail->prev;
        tail->next = nullptr;
        --size;
        delete temp;
        return val;
    }

    T pop_front() {
        if (!head)
            throw std::runtime_error{"pop_front: list is empty"};

        Node<T>* temp = head;
        T val = head->val;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        return val;
    }

    void printlist() {
        Node<T>* node = head;
        while (node) {
            std::cout << node->val << std::endl;
            node = node->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DLinkedList<int> list;
    list.push_back(10)->push_back(20)->push_back(30)->push_back(40);
    list.printlist();

    std::cout << list.pop_back() << std::endl;
    std::cout << list.pop_back() << std::endl;
    std::cout << list.pop_back() << std::endl;
    return 0;
}
