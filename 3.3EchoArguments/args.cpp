#include <iostream>

/**
 * When we execute the binary and pass some arguments throught the cli, those
 * arguments are forwared to the main function int argc = argument count char
 * **argv = argument values. argv represents an array of C-style strings, meaning each element in this array is an array of chars
 * therfore, argv is basically a 2-D array hence  = char **argv
 */
int main(int argc, char **argv) {

  std::cout << "Number of arguments passed " << argc << std::endl;

  for (int i = 0; i < argc; i++) {
    // using pointer arithmetic and the fact that array element are in contigous mem location
    std::cout << *(argv + i) << std::endl;
  }

  return 0;
}
