
#include <filesystem>
#include <iomanip>
#include <iostream>

/**
 * Crawl a given path and print out all the directories and files
 * If the current file is normal file then print it's name
 * If it's a directory then open it and do the same for it
 * Also the indentation should increase as we go deeper into the directories and should automatically decrese as we come out of them
 * So it changes with every level
 */
void crawl(std::filesystem::path, std::string indent = "");

int main() {
    std::filesystem::path p = "../../dsa";
    crawl(p);
    return 0;
}

// Default args only need to be specified in function declaration, not in function declaration
void crawl(std::filesystem::path filename, std::string indent) {
    std::cout << filename.filename().string() << std::endl;
    if (std::filesystem::is_regular_file(filename)) {
        // base case
        std::cout << indent << filename.filename().string() << std::endl;
    } else {
        try {
            //  it's directory (recursive case)
            for (const auto& entry : std::filesystem::directory_iterator(filename)) {
                crawl(entry.path(), indent + "-->");  // recursively call the same function for all files
                // also if it's directory, meaning we're going one level deeper, we increase the indentation by appending the 'indent' string
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
}
