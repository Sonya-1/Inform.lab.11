#include <string>
#include <iostream>
#include <filesystem>
#include "path.h"
namespace fs = std::filesystem;

void print_path(std::string path) {
    bool exists = fs::exists(path);

    if (!exists) {
        std::cout << "path not exists" << std::endl;
        exit(1);
    }
    const fs::directory_iterator iter = fs::directory_iterator(path);

    for (const fs::directory_entry entry : iter) {
        fs::path fullname = entry.path();
        fs::path basename = fullname.filename();
        std::cout << basename << std::endl;
    }
}
