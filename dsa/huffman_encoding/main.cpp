
#include <fstream>
#include <iostream>
#include <stdexcept>
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
void extractBits(const string& filename, vector<bool>& bits);

int main() {
    Queue pqueue;
    unordered_map<char, int> charFreq{};
    string inputFile = "input";
    string compFileName = "input_compressed";
    string decompFilename = "input_copy";
    ifstream file{inputFile};

    if (!file.is_open()) {
        throw runtime_error{"Failed to open text file"};
        return 1;
    }

    // 1. counting character frequency of the Text file
    countCharFreq(file, charFreq);

    // 2. building a Priority queue using frequency map
    buildPrioQueue(pqueue, charFreq);

    // 3. building the Huffman Binary Tree from this queue
    buildHuffmanTree(pqueue);

    // 4. construct a binary Tree object using this node
    BinaryTree huffmanTree{pqueue.dequeue()};

    // 5. Walk the Huffman Binary Tree and map each character to it's binary code
    unordered_map<char, string> huffmanCodes;
    huffmanTree.mapBinaryCode(huffmanCodes);

    // 6. Read the original data again, and build an encodedString (a binary string)
    string encodedString;
    encodeData(file, huffmanCodes, encodedString);

    // 7. Final step: obtain individual bytes from the encodedString and write them to the output file
    writeToEncodedFile(encodedString, compFileName);

    // ====== Decoding =======
    // 1. Read the entire file and extract individual bits into a vector
    vector<bool> bits;
    extractBits(compFileName, bits);

    // 2. Decode the entire file using this list of bits and by walking the huffmanTree to find characters
    huffmanTree.decompressFile(decompFilename, bits);

    file.close();
    return 0;
}

// Counts frequency of each character in the Text file
// file: refrence to ifStream file object
// charFreq : reference to the an empty map<char, int>
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
// - pqueue: a reference to the priority queue object
// - charFreq : a map containing frequencies of each character in the text file
void buildPrioQueue(Queue& pqueue, unordered_map<char, int>& charFreq) {
    for (auto elem : charFreq) {
        pqueue.enqueue(elem.first, elem.second);
    }
}

// Builds a Huffman Tree from the given priorityQueue
// dequque() first 2 nodes from the Queue, makes a newNode and enqueues() the newNode back to the queue
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

// Reads the file, single char at a time, and builds a 'binary string' by looking up huffman codes for each character in the map
// - ifstream& file: original text file containting text data
// - huffmanCodes : A map containing characters and their huffman codes
// - encodedString: A string to which all the charcter codes will be appended
void encodeData(ifstream& file, unordered_map<char, string>& huffmanCodes, string& encodedString) {
    file.clear();  // clear the EOF flag
    file.seekg(0, std::ios::beg);  // move the cursor back to beginning

    char ch;
    while (file.get(ch)) {
        encodedString += huffmanCodes[ch];
    }
}

// Groups the encoded data into individual bytes (8 bits) and writes them to the output file
// - encdoedString: string that contains all the encoded bit data
// - outFilename: filename for the output file
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
    // checking for remaining bits and making it a whole byte if necessary
    if (bitCount > 0) {
        byte = byte << (8 - bitCount);
        file.put(byte);
    }
    file.close();
}

// Extracts individual bits from the compressed binary file and puts them into a vector
// - filename : name of compressed file
// - bits : vector in which all the individual bits are inserted
void extractBits(const string& filename, vector<bool>& bits) {
    ifstream compressedFile(filename, ios::binary);

    if (!compressedFile.is_open()) {
        throw runtime_error{"Failed to open the compressed file"};
    }

    char byte;
    while (compressedFile.get(byte)) {
        for (int i = 7; i >= 0; i--) {
            // First iteration brings the MSB to the LSB place and the whole byte is either (00000000) or (00000001)
            // & 1 returns either 1 or 0 which gets stored in the boolean
            // same thing is repeated for every other bit in the byte
            bool bit = (byte >> i) & 1;
            bits.push_back(bit);
        }
    }

    compressedFile.close();
}
