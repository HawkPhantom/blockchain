#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"

class Blockchain {
public:
    Blockchain();  // Constructor declaration

    // Public method to get the blockchain
    const std::vector<Block>& getChain() const;

private:
    std::vector<Block> chain;
};

#endif // BLOCKCHAIN_H
