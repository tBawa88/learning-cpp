
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
void buildHuffmanTree(Queue& pqueue);
void encodeData(ifstream& file, unordered_map<char, string>& huffmanCodes, string& encodedString);
void writeToEncodedFile(string& encodedString, const string& outFilename);

int main() {
    Queue pqueue;
    unordered_map<char, int> charFreq{};
    ifstream file{"input"};

    if (!file.is_open()) {
        cerr << "Error opening the file " << endl;
        return 1;
    }

    // 1. counting character frequency of the Text file
    countCharFreq(file, charFreq);

    // 2. building a Priority queue using frequency map
    buildPrioQueue(pqueue, charFreq);

    // 3. building the Huffman Binary Tree from this queue
    buildHuffmanTree(pqueue);

    // 4. construct a binary Tree object using this node
    BinaryTree tree{pqueue.dequeue()};

    // 5. Walk the Huffman Binary Tree and map each character to it's binary code
    unordered_map<char, string> huffmanCodes;
    tree.mapBinaryCode(huffmanCodes);

    // 6. Read the original data again, and build an encodedString (a binary string)
    string encodedString;
    encodeData(file, huffmanCodes, encodedString);

    // 7. Final step: obtain individual bytes from the encodedString and write them to the output file
    writeToEncodedFile(encodedString, "output");

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
// Builds a priority queue. Stores each character by taking it's frequency value as priority
void buildPrioQueue(Queue& pqueue, unordered_map<char, int>& charFreq) {
    for (auto elem : charFreq) {
        pqueue.enqueue(elem.first, elem.second);
    }
}

// Builds a Huffman Tree from the given priorityQueue
void buildHuffmanTree(Queue& pqueue) {
    while (pqueue.size() > 1) {
        Node* first = pqueue.dequeue();
        Node* second = pqueue.dequeue();

        Node* newnode = new Node(first->priority + second->priority, first, second);
        newnode->ch = '`';
        // enqueue this new node back into the pqueue
        pqueue.enqueue(newnode);
    }
}

// encodeData() reads the file single char at a time, and builds a 'binary string'
// by looking up huffman codes for each character in the map
// - Takes in a ifStream& object
// - A map which contains characters and their huffman codes
// - An empty string to which all the charcter codes will be added
void encodeData(ifstream& file, unordered_map<char, string>& huffmanCodes, string& encodedString) {
    file.clear();  // clear the EOF flag
    file.seekg(0, std::ios::beg);  // move the cursor to beginning

    char ch;
    while (file.get(ch)) {
        encodedString += huffmanCodes[ch];
    }
}

// Groups the encoded data into individual bytes (8 bits) and writes them to the output file
// - Takes a string that contains all the encoded bit data
// - A filename for the output file
void writeToEncodedFile(string& encodedString, const string& outFilename) {
    ofstream file(outFilename);
    int bitCount = 0;
    unsigned char byte;  // size of unsigned char is exactly 1 byte (8 bits)  which makes it ideal to represent a single byte

    // since encoded string contains 0s and 1s, we're calling each character a bit
    for (char bit : encodedString) {
        // left shit byte to make space for a new bit
        // bit - '0' returns either int 1 or int 0, which is then added to the bit
        byte = (byte << 1) | (bit - '0');
        bitCount++;

        if (bitCount == 8) {
            file.put(byte);
            bitCount = 0;
            byte = 0;
        }
    }

    // check for any remaining bits
    if (bitCount > 0) {
        byte = byte << (8 - bitCount);  // this will left shif byte by adding 0s to the right side
        file.put(byte);
    }

    file.close();
}
