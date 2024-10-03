#include <iostream>
#include "Trimer.h"

#define EXAMPLE_FILE_PATH "markdown_example.txt"

int main(int argc, char* argv[]) {
    std::string path = argc == 2 ? argv[1] : EXAMPLE_FILE_PATH;
    std::cout << "File path: " << path << std::endl << std::endl;

    Trimer trimer = Trimer(path);

    std::cout << "==Headers==" << std::endl;
    for (const auto& header : trimer.Headers) {
        std::cout << header << std::endl;
    }

    std::cout << "\n==Paragraphs==" << std::endl;
    for (const auto& paragraph : trimer.Paragraphs) {
        std::cout << paragraph << std::endl;
    }

    std::cout << "\n==Links==" << std::endl;
    for (const auto& link : trimer.Links) {
        std::cout << link << std::endl;
    }
    return 0;
}