#include <math.h>

#include <iostream>

using namespace std;

#include "HashSet.h"

template <typename SetType>
HashSet<SetType>::HashSet(unsigned long cap) {
    capacity = cap;
    set_size = 0;
    table = new HashNode<SetType>*[cap];
    for (int i = 0; i < cap; i++)
        table[i] = nullptr;
}
template <typename SetType>
HashSet<SetType>::~HashSet() { clear(); }

template <typename SetType>
int HashSet<SetType>::hashFunction(const SetType& val) const {
    return abs(static_cast<int>(val % capacity));
}

template <typename SetType>
void HashSet<SetType>::insert(const SetType& val) {
    if (!contains(val)) {
        int index = hashFunction(val);
        HashNode<SetType>* newNode = new HashNode<SetType>(val);
        HashNode<SetType>* head = table[index];
        if (!head) {
            table[index] = newNode;
        } else {
            while (head->next) {
                head = head->next;
            }
            head->next = newNode;
        }
        set_size++;
    }
}

template <typename SetType>
bool HashSet<SetType>::contains(const SetType& val) const {
    int index = hashFunction(val);
    if (!table[index]) return false;

    HashNode<SetType>* head = table[index];

    while (head) {
        if (head->val == val)
            return true;
        head = head->next;
    }
    return false;
}

template <typename SetType>
void HashSet<SetType>::remove(const SetType& val) {
    if (contains(val)) {
        int index = hashFunction(val);
        HashNode<SetType>** current = &table[index];
        // HashNode<SetType>* prev = nullptr;
        while ((*current) != nullptr) {
            if ((*current)->val == val) {
                HashNode<SetType>* trash = *current;
                *current = (*current)->next;
                delete trash;
                break;
            }
            current = &(*current)->next;
        }
        set_size--;
    }
}

template <typename SetType>
unsigned long HashSet<SetType>::size() { return this->set_size; }

template <typename SetType>
bool HashSet<SetType>::empty() { return this->set_size == 0; }

template <typename SetType>
void HashSet<SetType>::clear() {
    for (int i = 0; i < capacity; i++) {
        if (table[i] != nullptr) {
            clearList(table[i]);
        }
    }
}

template <typename SetType>
void HashSet<SetType>::clearList(HashNode<SetType>* head) {
    while (head) {
        HashNode<SetType>* nxt = head->next;
        delete head;
        head = nxt;
    }
}
