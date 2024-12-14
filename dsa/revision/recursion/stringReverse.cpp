#include <string>

std::string reverseString(std::string);
std::string helperFunc(std::string, std::string);

std::string reverseString(std::string str) {
    if (str.size() <= 1)
        return str;
    return helperFunc(str, "");
}

std::string helperFunc(std::string str, std::string rev) {
    if (str.size() < 1)
        return rev;

    // extract the last character
    // slice the string
    // build the new reverse string by simply appending it with the extracted char
    char c = str[str.size() - 1];
    return helperFunc(str.substr(0, str.size() - 1), rev + c);
}
