#include <algorithm>
#include <iostream>
#include <set>
#include <string>

void permutationsHelper(std::string s, std::string prefix = "");
void permutationsHelper(std::string s, std::set<std::string>& dupeSet, std::string prefix = "");
void generatePermutationsHelper(std::string& s, int current);

void ListPermutations(std::string s) {
    // std::set<std::string> dupeSet;
    // permutationsHelper(s, dupeSet);

    // first sort the string to bring duplicate characters together
    std::sort(s.begin(), s.end());
    generatePermutationsHelper(s, 0);
}

// This version only prints unique permutations BUT uses a set to keep track of previously generated strings
void permutationsHelper(std::string str, std::set<std::string>& dupeSet, std::string prefix) {
    if (str.size() == 0 && !dupeSet.contains(prefix)) {
        std::cout << prefix << std::endl;
        dupeSet.insert(prefix);
    } else {
        for (int i = 0; i < str.size(); i++) {
            char c = str[i];
            std::string newStr = str.substr(0, i) + str.substr(i + 1);
            permutationsHelper(newStr, dupeSet, prefix + c);
        }
    }
}

/**
 * Removing duplicate permutations of a string that contains duplicate characters is done using recursive backtracking
 * The apporach is that we start with first character, and swap it with all the non-duplicate characters to generate different combinations of the string
 *
 *
 */
void generatePermutationsHelper(std::string& str, int current) {
    if (current == str.length()) {
        std::cout << str << std::endl;
    } else {
        for (int i = current; i < str.length(); i++) {
            // skip the duplicate chars
            if (i != current && str[i] == str[current]) {
                continue;
            }

            // swapping will generate different permutations : CHOOSE
            std::swap(str[current], str[i]);

            // recursively call the function to generate other permutations : EXPLORE
            generatePermutationsHelper(str, current + 1);

            // restore the original string : UnCHoose
            std::swap(str[current], str[i]);
        }
    }
}

// This version prints all possible permutations regardless of the duplicate characters
void permutationsHelper(std::string str, std::string prefix) {
    if (str.size() == 0) {
        std::cout << prefix << std::endl;
    } else {
        for (int i = 0; i < str.size(); i++) {
            char c = str[i];
            std::string newStr = str.substr(0, i) + str.substr(i + 1);
            permutationsHelper(newStr, prefix + c);
        }
    }
}
