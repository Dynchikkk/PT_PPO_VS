#include "Trimer.h"

Trimer::Trimer(const std::string& filename)
{
    _filename = filename;
    ExtractContent();
}

void Trimer::ExtractContent()
{
    std::ifstream file(_filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error when open file\n");
    }
    std::string line;
    std::regex headerRegex(R"(^#{1,6}\s*(.*))");
    std::regex paragraphRegex(R"(^\s*(\S.*))");
    std::regex linkRegex(R"(\[([^\]]+)\]\(([^)]+)\))");
    std::regex pattern("Discord|Google");

    while (std::getline(file, line)) {
        std::smatch match;
        if (std::regex_match(line, match, headerRegex)) {
            Headers.push_back(match[1]);
        }
        else if (std::regex_match(line, match, paragraphRegex)) {
            Paragraphs.push_back(match[1]);
        }

        auto words_begin = std::sregex_iterator(line.begin(), line.end(), linkRegex);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            std::string nf = match[1];
            std::string stars = "";
            for (int i = 0; i < nf.length(); i++)
                stars += '*';
            std::string name = std::regex_replace(nf, pattern, stars);
            name += " ";
            name += match[2];
            Links.push_back(name);
        }
    }
}