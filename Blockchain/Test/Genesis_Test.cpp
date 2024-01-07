#include <iostream>
#include <filesystem>
#include "../lib/ConfigReader.h"
#include "../lib/HeadersConverter.h"
#include "../lib/Block.h"
#include "../lib/Blockchain.h"  // Include your Blockchain header

// Function to display the contents of a block

void printBlock(const Block& block) {
    const BlockHeaders& headers = block.getHeaders();
    std::cout << "Printing Block..." << std::endl;
    std::cout << "Block: { "
              << "parentHash: " << headers.parentHash
              << ", beneficiary: " << headers.beneficiary
              << ", difficulty: " << headers.difficulty
              << ", number: " << headers.number
              << ", timestamp: " << headers.timestamp
              << ", nonce: " << headers.nonce
              << " }" << std::endl;
}

int main() {
    Blockchain blockchain;

    std::cout << "Blockchain initialized" << std::endl;

    // Iterate over the blockchain and print each block
    for (const auto& block : blockchain.getChain()) {
        printBlock(block);
    }

    return 0;
}
