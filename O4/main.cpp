#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

/**
 * @brief reads a file and returns a vector of strings
 * @param path the path to the file
 * @return a vector of strings
 * @throw std::runtime_error if the file could not be opened
*/
std::vector<std::string> read_file(std::string path) {
    std::string line;
    std::ifstream file(path);
    std::vector<std::string> lines;
    if (file.is_open()) {
        while (getline(file, line)) {
            lines.push_back(line);
        }
    } else {
        throw std::runtime_error("Unable to open file!");
    }
    return lines;
}

/**
 * @brief makes a map of characters and their counts
 * @param lines a vector of strings
 * @return a map of characters and their counts
*/
std::map<char, int> make_map(std::vector<std::string> lines) {
    std::map<char, int> counts;
    for (const auto &str : lines) {
        for (char c : str) {
            if (!isascii(c)) {
                continue;
            }
            ++counts[c];
        }
    }
    return counts;
}

/**
 * @brief makes a vector of strings lowercase
 * @param lines a vector of strings
 * @return a vector of strings
*/
std::vector<std::string> make_lower(std::vector<std::string> lines) {
    std::vector<std::string> new_lines;

    for (const auto &line : lines) {
        std::string new_line;
        for (const auto &c : line) {
            new_line += std::tolower(c);
        }
        new_lines.push_back(new_line);
    }
    return new_lines;
}

/**
 * @brief main function
 * @details reads a file, makes a map of characters and their counts, and
 * prints the amount of characters, lines, and alphabetical characters
 * @details the file is hardcoded to "bible.txt"
 * @return 0
*/
int main() {
    int char_count = 0;
    int char_is_alpha = 0;
    std::vector<std::string> lines = read_file("bible.txt");
    std::map<char, int> counts = make_map(lines);

    for (const auto &count : counts) {
        char_count += count.second;
        if (std::isalpha(count.first)) {
            char_is_alpha += count.second;
        }
    }

    for (const auto &count : counts) {
        char_count += count.second;
        if (std::isalpha(count.first)) {
            char_is_alpha += count.second;
        }
    }

    std::cout << "amount of characters is: " << char_count << std::endl;
    std::cout << "amount of lines is: " << lines.size() << std::endl;
    std::cout << "amount of alphabetical characters is: " << char_is_alpha
              << std::endl;
    return 0;
}