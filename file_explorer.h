//
// Created by Rasul Mammadov on 02.04.25.
//

#ifndef FILE_EXPLORER_H
#define FILE_EXPLORER_H
#include <string>
#include <vector>
#include <filesystem> // Don't forget about -std=c++17 flag.

namespace fs = std::filesystem;

inline std::vector<std::string> allFiles;
class file_explorer {
public:
    bool file_explore(const fs::path &directory);
    //file_explorer(const std::string& s);
    //std::vector<std::string> findedFiles;
    static std::vector<std::string> getDirectoryFiles(const fs::path &directory);
    static std::vector<std::string> findFiles(const std::string& str_to_find);

};



#endif //FILE_EXPLORER_H
