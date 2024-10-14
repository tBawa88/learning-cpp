#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class ArrayList {
    T* arr;
    unsigned int len;
    size_t cap;

   public:
    ArrayList(size_t l = 5);
    ~ArrayList();
    void add(const T& value);
    void pop();
    void insert(int index, const T& value);
    void set(int index, const T& value);
    T& get(int index);
    int indexOf(const T& value);
    int size();
    void remove(int index);
    bool contains(const T& value);
    bool isEmpty();

    T& operator[](int index);  // for read-write access
    const T& operator[](int index) const;  // for read only acces
    // it's important to make sure that along with the const return type, the function is also of const type
    // because just the difference in return type is not sufficient for overloading
};

// Initializes a list with given size. Default value of size if 5
template <typename T>
ArrayList<T>::ArrayList(size_t l) : cap{l}, len{0} {
    arr = new T[cap];
}

template <typename T>
ArrayList<T>::~ArrayList() { delete[] arr; }

// add() adds a new element to the back of the list
template <typename T>
void ArrayList<T>::add(const T& value) {
    // potential resizing of the array
    if (len == cap) {
        cap = cap * 2;
        T* newlist = new T[cap];
        for (int i = 0; i < len; i++) {
            newlist[i] = arr[i];
        }
        delete[] arr;
        arr = newlist;
    }
    arr[len++] = value;
}

// insert() adds a new element at the given index. It throws a runtime_error if the index is invalid
template <typename T>
void ArrayList<T>::insert(int index, const T& value) {
    if (index < 0 || index >= len) {
        throw std::runtime_error{"ArrayList.insert(): Invalid index"};
    }
    // potential resizing of the array
    if (len == cap) {
        cap = cap * 2;
        T* newlist = new T[cap];
        for (int i = 0; i < len; i++) {
            newlist[i] = arr[i];
        }
        delete[] arr;
        arr = newlist;
    }

    // first move every element starting from that index one place to the right
    for (int i = len; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    ++len;
}

// pop() removes the last element of the list
template <typename T>
void ArrayList<T>::pop() {
    if (len > 0)
        len--;
}

// set() updates the value at given index. It throws a runtime_error if the index is invalid
template <typename T>
void ArrayList<T>::set(int index, const T& value) {
    if (index < 0 || index >= len) {
        throw std::runtime_error{"ArrayList.set(): Invalid array index"};
    }

    arr[index] = value;
}

// get() returns the value at given index. It throws a runtime_error if the index is invalid
template <typename T>
T& ArrayList<T>::get(int index) {
    if (index < 0 || index >= len) {
        throw std::runtime_error{"ArrayList.get(): Invalid array index"};
    }

    return arr[index];
}

// size() returns current number of elements in the list
template <typename T>
int ArrayList<T>::size() { return len; }

// remove() removes the element at given index from the list. It throws a runtime_error if index is invalid
template <typename T>
void ArrayList<T>::remove(int index) {
    if (index < 0 || index >= len) {
        throw std::runtime_error{"ArrayList.remove(): Invalid array index"};
    }

    // resize if len drops below half capacity
    if (len < cap / 2) {
        cap = cap / 2;
        T* newarr = new T[cap];
        for (int i = 0; i < len; i++) {
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
    }

    for (int i = index; i < len - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[len - 1] = T();  // setting the last element as default value of T, tis optional
    --len;
}

// indexOf() finds the first occurence of the given value and returns it's index. Returns -1 if not found
template <typename T>
int ArrayList<T>::indexOf(const T& value) {
    // do a linear search
    for (int i = 0; i < len; i++) {
        if (value == arr[i]) {
            return i;
        }
    }
    return -1;
}

// contains() returns true if the element is found in the list.
template <typename T>
bool ArrayList<T>::contains(const T& value) {
    // do a linear search
    for (int i = 0; i < len; i++) {
        if (value == arr[i]) {
            return true;
        }
    }
    return false;
}

// isEmpty() returns true if the current list is empty
template <typename T>
bool ArrayList<T>::isEmpty() { return len == 0; }

// overloading of subscript operators
// this overload returns an element from the underlying array and provides read-write access to that element
template <typename T>
T& ArrayList<T>::operator[](int index) {
    if (index < 0 || index >= len) {
        throw std::runtime_error{"Invalid array index"};
    }
    return arr[index];
}

// this overload returns the element but only for read access
template <typename T>
const T& ArrayList<T>::operator[](int index) const {
    if (index < 0 || index >= len) {
        throw std::runtime_error{"Invalid array index"};
    }
    return arr[index];
}

template <typename T>
std::ostream& operator<<(std::ostream& out, ArrayList<T>& list) {
    out << "[";
    for (int i = 0; i < list.size(); i++) {
        out << list[i];
        if (i < list.size() - 1)
            out << ",";
    }
    out << "]";
    return out;
}
