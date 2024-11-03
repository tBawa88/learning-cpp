#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

#include "BST.h"
#include "BinaryTree_huffman.h"
#include "Node.h"
#include "Treenode.h"
#include "priority_queue.h"
using namespace std;

void countCharFreq(ifstream& file, unordered_map<char, int>& charFreq);
void buildPrioQueue(Queue& pqueue, unordered_map<char, int>& charFreq);
void printFreqMap(unordered_map<char, int>& charFreq);

int main() {
    Queue pqueue;
    unordered_map<char, int> charFreq{};
    ifstream file{"textfile.txt"};

    if (!file.is_open()) {
        cerr << "Error opening the file " << endl;
        return 1;
    }

    // counting character frequency of the Text file
    countCharFreq(file, charFreq);

    // building a Priority queue using frequency map
    buildPrioQueue(pqueue, charFreq);

    // building the Binary Tree from this queue
    while (pqueue.size() > 1) {
        Node* first = pqueue.dequeue();
        Node* second = pqueue.dequeue();

        Node* newnode = new Node(first->priority + second->priority, first, second);
        newnode->ch = '`';
        // enqueue this new node back into the pqueue
        pqueue.enqueue(newnode);
    }

    // construct a binary Tree using this node
    BinaryTree tree{pqueue.dequeue()};

    // testing out the binary Tree
    tree.printSideways();

    file.close();
    return 0;
}

// Takes in a ifStream object, reads each character from it and builds the frequency map
void countCharFreq(ifstream& file, unordered_map<char, int>& charFreq) {
    char ch;
    while (file.get(ch)) {
        charFreq[ch]++;
    }
    if (file.eof()) {
        charFreq['\0']++;
    }
}

void buildPrioQueue(Queue& pqueue, unordered_map<char, int>& charFreq) {
    for (auto elem : charFreq) {
        pqueue.enqueue(elem.first, elem.second);
    }
}

// Prints contents of the char frequency map
void printFreqMap(unordered_map<char, int>& charFreq) {
    printf("ASCII : Frequency\n");
    for (auto elem : charFreq) {
        printf("%d -> %d\n", elem.first, elem.second);
    }
}
