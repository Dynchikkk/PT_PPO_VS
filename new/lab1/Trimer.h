#ifndef TRIMER
#define TRIMER

#include <fstream>
#include <string>
#include <regex>
#include <vector>

class Trimer
{
public:
    std::vector<std::string> Headers;
    std::vector<std::string> Paragraphs;
    std::vector<std::string> Links;

    Trimer(const std::string& filename);

private:
    std::string _filename;
    void ExtractContent();
};
#endif

