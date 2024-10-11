# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20

# Source files
SRCS = main.cpp Board.cpp queenUtils.cpp

# Output executable
TARGET = main

# Rule to build the project
$(TARGET): $(SRCS)
	$(CXX) $(SRCS) $(CXXFLAGS) -o $(TARGET)

# Clean rule to remove compiled files
clean:
	rm -f $(TARGET)
