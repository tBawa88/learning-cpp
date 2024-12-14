#include <string>

bool isPallindrome(std::string& str);
bool pallindrome_helper(std::string& str, int low, int high);

/**
 * - Compare the first and the last characters of the string
 * - If they're same, then slice the string by removing the first and last characters and recrusively call the function with the new string
 *      - else return false
 * - If string is empty return true
 */
bool isPallindrome(std::string& str) {
    return pallindrome_helper(str, 0, str.size() - 1);
}

bool pallindrome_helper(std::string& str, int low, int high) {
    if (str.size() == 0 || high <= low)
        return true;

    if (str[low] == str[high])
        return pallindrome_helper(str, low + 1, high - 1);
    else
        return false;
}
