#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cctype>

std::vector<std::string> read_file(std::string path){
    std::string line;
    std::ifstream file(path);
    std::vector<std::string> lines;
    if (file.is_open()){
        while (getline(file, line)){
            lines.push_back(line);
        }
    }
    else{
        throw std::runtime_error("Unable to open file!");
    }
    return lines;
}

std::map<char,int> make_map(std::vector<std::string> lines){
    std::map<char, int> counts;
    for (const auto &str : lines){
        for (char c : str){
            if ( !isascii(c)){  continue;   }
            ++counts[c];
        }
    }
    return counts;
}

std::vector<std::string> make_lower(std::vector<std::string> lines){
    std::vector<std::string> new_lines;

    for (const auto &line : lines){
        std::string new_line;
        for (const auto &c : line){
            new_line += std::tolower(c);
        }
        new_lines.push_back(new_line);
    }
    return new_lines;
}

int main(){    
    int char_count = 0;
    int char_is_alpha = 0;
    std::vector<std::string> lines = read_file("bible.txt");
    std::map<char, int> counts = make_map(lines);

    for (const auto &count : counts){
        char_count += count.second;
        if (std::isalpha(count.first)){
            char_is_alpha += count.second;
        }
    }

    for (const auto &count : counts){
        char_count += count.second;
        if (std::isalpha(count.first)){
            char_is_alpha += count.second;
        }
    }

    std::cout << "amount of characters is: " << char_count << std::endl;
    std::cout << "amount of lines is: " << lines.size() << std::endl;
    std::cout << "amount of alphabetical characters is: " << char_is_alpha << std::endl;
    return 0;
}