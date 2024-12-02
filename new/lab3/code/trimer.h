#ifndef TRIMER_H
#define TRIMER_H

#include <string>
#include <vector>
#include <fstream>
#include <regex>
#include <stdexcept>

class Trimer {
public:
    Trimer(const std::string& filename);
    std::vector<std::string> Headers;
    std::vector<std::string> Paragraphs;
    std::vector<std::string> Links;

private:
    std::string _filename;
    void ExtractContent();
};

#endif // TRIMER_H
