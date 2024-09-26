#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

#define EXAMPLE_FILE_PATH "markdown_example.txt"

struct Content {
    std::vector<std::string> headers;
    std::vector<std::string> paragraphs;
    std::vector<std::string> links;
};

Content extractContent(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error when open file\n");
    }

    Content content;
    std::string line;
    std::regex headerRegex(R"(^#{1,6}\s*(.*))");
    std::regex paragraphRegex(R"(^\s*(\S.*))");
    std::regex linkRegex(R"(\[([^\]]+)\]\(([^)]+)\))");

    while (std::getline(file, line)) {
        std::smatch match;
        if (std::regex_match(line, match, headerRegex)) {
            content.headers.push_back(match[1]);
        }
        else if (std::regex_match(line, match, paragraphRegex)) {
            content.paragraphs.push_back(match[1]);
        }

        auto words_begin = std::sregex_iterator(line.begin(), line.end(), linkRegex);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            content.links.push_back(match[2]);
        }
    }

    return content;
}

int main(int argc, char* argv[]) {
    std::string path = argc == 2 ? argv[1] : EXAMPLE_FILE_PATH;
    std::cout << "File path: " << path << std::endl << std::endl;

    Content content = extractContent(path);

    std::cout << "==Headers==" << std::endl;
    for (const auto& header : content.headers) {
        std::cout << header << std::endl;
    }

    std::cout << "\n==Paragraphs==" << std::endl;
    for (const auto& paragraph : content.paragraphs) {
        std::cout << paragraph << std::endl;
    }

    std::cout << "\n==Links==" << std::endl;
    for (const auto& link : content.links) {
        std::cout << link << std::endl;
    }

    return 0;
}