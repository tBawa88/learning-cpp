#include <iostream>
#include <stdexcept>

using namespace std;

#ifndef _hash_set_
#define _hash_set_

template <typename SetType>
struct HashNode {
    SetType val;
    HashNode* next;

    HashNode(const SetType& val, HashNode* next = nullptr) {
        this->val = val;
        this->next = next;
    }
    ~HashNode() {
        cout << "node cleared: " << val << endl;
    }
};

/**
 * Class : HashSet
 * ----------------
 * Implements a hash based Set data structure which stores a colllection of unique values
 */
template <typename SetType>
class HashSet {
   public:
    HashSet(unsigned long cap = 259);
    ~HashSet();

    /**
     * Inserts value in the hash set. Ignores duplicates values
     */
    void insert(const SetType& val);

    /**
     * Returns true if the value exists in the set
     */
    bool contains(const SetType& val) const;

    /**
     * Removes the value from the set if it exists
     */
    void remove(const SetType& val);

    /**
     * Clears out the set, frees the memory allocated to each node
     */
    void clear();

    /**
     * Returns the number of elements present in the set
     */
    unsigned long size();

    /**
     * Returns true if there are no elements in the set
     */
    bool empty();

   private:
    /**
     * An array of pointers. Each element in the array is a head pointer to a Linked List
     */
    HashNode<SetType>** table;
    unsigned long capacity;
    unsigned long set_size;
    /**
     * Produces the hash code (Array index) from the given integer value
     * Currently only works for integer values
     */
    int hashFunction(const SetType& val) const;

    void clearList(HashNode<SetType>* head);
};
#include "HashSet_impl.cpp"

#endif