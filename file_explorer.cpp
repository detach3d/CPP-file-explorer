#include <string>
#include <filesystem> // Don't forget about -std=c++17 flag.
#include <vector>
#include <exception>
#include "file_explorer.h"

#include <iostream>

namespace fs = std::filesystem;

bool file_explorer::file_explore(const std::string &s) {
    allFiles.clear();
    try {
        allFiles = getDirectoryFiles(s);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        std::string s = e.what();

        if (s.find("No such file or directory") != std::string::npos) {
            std::set_terminate(nullptr);
            allFiles.push_back("Not found");
            return true;
        }else {
            allFiles.push_back("Permission denied");
            return true;
        }
    }
    if (!allFiles.empty()) {
        return true;
    }

    return false;
}


std::vector<std::string> file_explorer::getDirectoryFiles(const fs::path &directory) {

    std::vector<std::string> files{};

    for (const auto &file: fs::recursive_directory_iterator(directory)) {
        if (fs::exists(file.path())) {
            files.push_back(file.path().string());
        }
        //std::cout << file.path().string() << std::endl;
    }
    return files;
}

std::vector<std::string> file_explorer::findFiles(const std::string &str_to_find) {
    std::vector<std::string> findedFiles{};
    for (const auto &file: allFiles) {
        if (file.find(str_to_find) != std::string::npos) {
            findedFiles.push_back(file);
        }
    }
    return findedFiles;
}
