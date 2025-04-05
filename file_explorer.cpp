#include <string>
#include <filesystem> // Don't forget about -std=c++17 flag.
#include <vector>
#include <exception>
#include "file_explorer.h"

#include <iostream>

namespace fs = std::filesystem;

int file_explorer::file_explore(const fs::path &directory) {
    allFiles.clear();
    try {
        allFiles = getDirectoryFiles(directory);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        std::string str = e.what();

        if (str.find("No such file or directory") != std::string::npos) {
            //std::cout << e.what() << std::endl;
            std::set_terminate(nullptr);
            allFiles.clear();
            allFiles.emplace_back("Directory not found");
            return 1;
        }
        if (str.find("Operation not permitted") != std::string::npos ||
            str.find("Permission denied") != std::string::npos) {
            //std::cout << e.what() << std::endl;
            std::set_terminate(nullptr);
            allFiles.clear();
            allFiles.emplace_back("Permission denied");
            return 1;
        }
    }
    if (!allFiles.empty()) {
        return 2;
    }

    return 3;
}

std::vector<std::string> file_explorer::getDirectoryFiles(const fs::path &directory) {
    std::vector<std::string> files{};

    for (const auto &file: fs::recursive_directory_iterator(directory)) {
        files.push_back(file.path().string());

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
