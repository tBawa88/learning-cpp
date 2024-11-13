#include "HashSet.h"

class Iterator {
    /*Iterator typedefs for C++ iterator compatibility*/
   public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = SetType;
    using difference_type = std::ptrdiff_t;
    using pointer = SetType*;
    using reference = SetType&;

    /*Constructor*/
    Iterator(
        HashNode<SetType>** table,
        int capacity,
        int bucketIndex = 0,
        HashNode<SetType>* node = nullptr) {
        this->table = table;
        this->capacity = capacity;
        this->bucketIndex = bucketIndex;
        this->currentNode = node;
    }

    /*Overloaded operatotrs*/
    // Derefrence operator
    SetType& operator*() const {
        return this->currentNode->val;
    }
    // Arrow operator
    SetType* operator->() const {
        return &(this->currentNode->val);
    }

    // Prefix Increment operator, for it++ (moving the iterator forward)
    Iterator& operator++() {
        if (currentNode)
            currentNode = currentNode->next;

        // Means we've reached the end of the linked list, increment the bucketIndex to next array index
        // and advance the currentnode to the next non-nullptr node in the table
        if (!currentNode) {
            ++bucketIndex;
            advanceToNextBucket();
        }
        return *this;
    }

    // Comparison operators are for checking it != set.end()
    // Equality comparison operator
    bool operator==(const Iterator& other) const {
        return currentNode == other.currentNode && bucketIndex == other.bucketIndex;
    }

    // In-Equality comparison operator
    bool operator!=(const Iterator& other) const {
        return !(*this == other);
    }
    /*Helper to skip to next non-empty bucket*/
    void advanceToNextBucket() {
        while (bucketIndex < capacity && !currentNode)
            currentNode = table[bucketIndex++];
    }

   private:
    HashNode<SetType>** table;
    int capacity;
    int bucketIndex;
    HashNode<SetType>* currentNode;
};
