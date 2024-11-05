CXX = g++
CXX_FLAGS = -std=c++20

TARGET = main

INPUT_FILE = input
COMPRESSED = input_compressed
INPUT_COPY = input_copy

SRC =  main.cpp BST.cpp BST_helpers.cpp Treenode.cpp priority_queue.cpp BinaryTree_huffman.cpp

build:
	$(CXX) $(CXX_FLAGS) $(SRC) -o $(TARGET)

clean:
	rm -rf $(TARGET) $(COMPRESSED) $(INPUT_COPY)
