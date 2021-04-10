#include <string>
#include <iostream>
#include <filesystem>
#include "path.h"
namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cout << "parameter need" << std::endl;
        exit(1);
    }
    std::string path = argv[1]; 

    print_path(path);

    return 0;
}