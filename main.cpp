#include <iostream>
#include <string>
#include <fstream>

std::string loadFile(const std::string &fileName);

int main() {
    std::string fileSrc = "/home/ultra/Projects/UPL/ExampleApp/index.upl";
    auto fileContent = loadFile(fileSrc);

    std::cout << fileContent << std::endl;
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