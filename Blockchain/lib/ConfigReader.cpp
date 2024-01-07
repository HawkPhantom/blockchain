#include "ConfigReader.h"
#include <fstream>
#include <iostream>

std::map<std::string, std::string> readGenesisConfig(const std::string& filename) {
    std::map<std::string, std::string> genesisData;
    std::ifstream file(filename);

    if (!file) {
        throw std::runtime_error("Unable to open config file: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::size_t delimiterPos = line.find('=');
        if (delimiterPos != std::string::npos) {
            std::string key = line.substr(0, delimiterPos);
            std::string value = line.substr(delimiterPos + 1);
            genesisData[key] = value;

            // Debug output
            std::cout << "Key: " << key << ", Value: " << value << std::endl;
        }
    }

    return genesisData;
}
