#include <algorithm>
#include <cctype>  // for std::toLower()
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
/**
 * We have a text book in this directory, let's run some operations on that. Open the file using std::ifstream and read some contents from that
 *
 */
std::string sort_letters(std::string);
std::string to_lowercase(std::string);
void list_of_anagrams(std::unordered_map<std::string, std::set<std::string>>&, std::string&);

int main() {
    std::ifstream file("book.txt");

    if (!file) {
        std::cerr << "Error opening the file " << std::endl;
    }

    std::string word;
    // std::unordered_set<std::string> wordset;
    // this loop read word by word and continues untill there are no more words left in the file
    std::unordered_map<std::string, std::set<std::string>> anagrams;
    while (file >> word) {
        std::string sorted = sort_letters(to_lowercase(word));  // find the sorted version of that word
        anagrams[sorted].insert(word);  // get the set that is mapped to this key, and insert the word into
    }

    while (true) {
        std::cout << "Enter a word to find it's anagram, 'quit' to exit: ";
        std::string input;
        std::cin >> input;
        if (input == "quit" || input == "") break;

        list_of_anagrams(anagrams, input);
    }

    // closing the file releases the file descriptor given to us by the OS
    file.close();
    return 0;
}

// pass by value, creates a copy and returs a sorted version of the string
std::string sort_letters(std::string str) {
    std::sort(str.begin(), str.end());
    return str;
}

std::string to_lowercase(std::string str) {
    // std::transform = applies a tranformation to a range of elements
    // 1st arg = starting point
    // 2nd arg = ending point
    // 3rd arg = where to put the transformation, in this case we want it to str.begin()
    // 4th = what transformation to be applied? since it's traversing over each character, we're using std::toLower() to turn every char into lowercase
    std::transform(
        str.begin(),
        str.end(),
        str.begin(),
        [](unsigned char c) { return std::tolower(c); });

    return str;
}

void list_of_anagrams(std::unordered_map<std::string, std::set<std::string>>& anagrams, std::string& input) {
    auto set = anagrams[sort_letters(to_lowercase(input))];
    std::cout << "list of anagrams: ";
    for (auto word : set) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}
