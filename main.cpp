#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::string loadFile(const std::string &fileName);
std::vector<std::string> splitTextByChar(const std::string& text, char delimiter);

int main() {
    std::string fileSrc = "/home/ultra/Projects/UPL/ExampleApp/index.upl";
    auto fileContent = loadFile(fileSrc);

    auto lines = splitTextByChar(fileContent, ';');

    for (auto &line : lines) {
        std::cout << line << std::endl;
    }
}

std::string loadFile(const std::string &fileName) {
    std::ifstream file(fileName);
    std::string fileContent;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            fileContent += line;
        }
        file.close();
    }

    return fileContent;
};

std::vector<std::string> splitTextByChar(const std::string& text, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;

    std::istringstream tokenStream(text);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}
