#include "BST.h"

// Constructors - Destructors
BST::BST() : root{nullptr} {}
BST::BST(Treenode* node) : root{node} {}
BST::~BST() { clear(); }

// Main ADT methods
bool BST::contains(const int& val) const { return contains(root, val); }
void BST::insert(const int& val) { insert(root, val); }
void BST::remove(const int& val) { remove(root, val); }
int BST::getMin() const { return getMin(root); }
int BST::getMax() const { return getMax(root); }
void BST::printSideways() const { printSideways(root, ""); }
void BST::print() const { print(root); }
bool BST::isEmpty() const { return length == 0; }
size_t BST::size() const { return length; }
void BST::clear() { clear(root); }
