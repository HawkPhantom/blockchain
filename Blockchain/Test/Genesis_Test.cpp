#include <iostream>
#include <filesystem>

#include "../lib/ConfigReader.h"
#include "../lib/HeadersConverter.h"
#include "../lib/Block.h"

int main() {
    try {
        // Get the current working directory as a string
        std::filesystem::path currentDir = std::filesystem::current_path();
        std::string currentDirStr = currentDir.string();

        // Move one step back from the current directory
        std::filesystem::path parentDir = currentDir.parent_path();
        std::string parentDirStr = parentDir.string();

        // Construct the full path to the "config" directory and "genesis.conf" file
        std::string configDirStr = parentDirStr + "/config";
        std::string configFileStr = configDirStr + "/genesis.conf";

        std::cout << "Current Directory: " << currentDirStr << std::endl;
        std::cout << "Parent Directory: " << parentDirStr << std::endl;
        std::cout << "Config Directory: " << configDirStr << std::endl;

        // Check if the "config" directory exists and "genesis.conf" is present
        if (std::filesystem::is_directory(configDirStr) && std::filesystem::exists(configFileStr)) {
            // Read the genesis configuration
            std::map<std::string, std::string> genesisHeadersMap = readGenesisConfig(configFileStr);

            // Convert the configuration data to BlockHeaders
            BlockHeaders genesisHeaders = convertToBlockHeaders(genesisHeadersMap);

            // Initialize the genesis block with the genesisHeaders
            Block genesisBlock(genesisHeaders);

            // Print the complete genesis block at once with cout
            std::cout << "Genesis Block is Created " << std::endl;
            std::cout << "Nonce: " << genesisBlock.getHeaders().nonce << std::endl;
            std::cout << "Parent Hash: " << genesisBlock.getHeaders().parentHash << std::endl;
        } else {
            std::cerr << "Error: 'config' directory not found or 'genesis.conf' not found in the parent directory" << std::endl;
            return 1;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
