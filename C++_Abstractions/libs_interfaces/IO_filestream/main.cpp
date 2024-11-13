#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

void copyFileNoComments(ifstream& infile, ofstream& outfile);

int main() {
    std::ifstream infile("program1.cpp");
    std::ofstream outfile("program2.cpp");

    if (!infile || !outfile) {
        std::cout << "failed to open files ";
        return 1;
    }

    copyFileNoComments(infile, outfile);

    infile.close();
    outfile.close();
    return 0;
}

/**
 *
 */
//

void copyFileNoComments(ifstream& infile, ofstream& outfile) {
    int currCh, nextCh;
    bool isComment = false;
    while ((currCh = infile.get()) != EOF) {
        if (!isComment) {
            // a comment can only start if the current char is / and the next char is * or /
            nextCh = infile.get();
            if (currCh == '/' && (nextCh == '*' || nextCh == '/')) {
                isComment = true;
                currCh = infile.get();  // move the currCh forward
            } else {
                infile.unget();
            }
        } else {
            // A commment can only end if the curent char is either * or /, and the next char is /
            nextCh = infile.get();
            if ((currCh == '*' || currCh == '/') && nextCh == '/') {
                isComment = false;
                currCh = infile.get();  // move the currCh forward
            } else {
                infile.unget();
            }
        }
        if (!isComment)
            outfile.put(currCh);
    }
}
