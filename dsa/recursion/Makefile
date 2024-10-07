CXX = g++
CXXFLAGS = -std=c++17 -I/home/userT/Desktop/stanford_cpp_lib/
# LDFLAGS = -L/home/userT/Desktop/stanford_cpp_lib/StanfordCPPLib -lstanfordcpplib

all:
	@echo "Please specify a afile to compile, e.g., make myfile.cpp"

%.cpp:
	$(CXX) $(CXXFLAGS) @ -o your_program $(@:cpp=)$(LDFLAGS)


