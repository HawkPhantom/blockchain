#include "Blockchain.h"
#include <iostream>

Blockchain::Blockchain() {
    std::cout << "Initializing blockchain..." << std::endl;
    // Initialize the blockchain with the genesis block
    chain.push_back(Block::genesis());
    std::cout << "Genesis block successfully added to the blockchain" << std::endl;
}

const std::vector<Block>& Blockchain::getChain() const {
    return chain;
}

const Block& Blockchain::getLatestBlock() const {
    return chain.back();
}
