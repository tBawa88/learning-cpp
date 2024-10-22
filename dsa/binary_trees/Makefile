# Compiler and flags variables
CXX = g++
CXXFLAGS = -std=c++20

# Source files
SRCS = main.cpp BinaryTree.cpp TreeNode.cpp

# target binary file name
TARGET = main

# optional rule -> if just 'make' is run, then the default values will be taken
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)
clean:
	rm -rf $(TARGET)
