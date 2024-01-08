#ifndef BLOCK_H
#define BLOCK_H

#include "blockHeaders.h"
#include <filesystem>
#include <map>
#include <string>
#include <iostream>
#include "../lib/Keccak256B.h"

// Function declarations for reading and converting the genesis configuration
std::map<std::string, std::string> readGenesisConfig(const std::string& configFileStr);
BlockHeaders convertToBlockHeaders(const std::map<std::string, std::string>& headersMap);

class Block {
public:
    // Constructor
    Block(const BlockHeaders& headers);

    static Block mineBlock(const Block& lastBlock, const std::string& beneficiary);


    // Static method to create the genesis block
    static Block genesis() {
        std::cout << "Creating Genesis Block..." << std::endl;
        std::filesystem::path currentDir = std::filesystem::current_path();
        std::string parentDirStr = currentDir.parent_path().string();
        std::string configFileStr = parentDirStr + "/config/genesis.conf";

        std::cout << "Checking config path: " << configFileStr << std::endl;

        if (std::filesystem::is_directory(parentDirStr + "/config") && 
            std::filesystem::exists(configFileStr)) {
            std::cout << "Config file found. Reading..." << std::endl;
            std::map<std::string, std::string> genesisHeadersMap = readGenesisConfig(configFileStr);
            BlockHeaders genesisHeaders = convertToBlockHeaders(genesisHeadersMap);
            std::cout << "Genesis Block Created." << std::endl;
            return Block(genesisHeaders);
        } else {
            std::cerr << "Genesis configuration not found" << std::endl;
            throw std::runtime_error("Genesis configuration not found");
        }
    }


    // Get headers
    const BlockHeaders& getHeaders() const { return blockHeaders; }

private:
    BlockHeaders blockHeaders;
};

#endif // BLOCK_H
