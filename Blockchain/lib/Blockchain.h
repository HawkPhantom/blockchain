#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"

class Blockchain {
public:
    Blockchain();  // Constructor

private:
    std::vector<Block> chain;
};

#endif // BLOCKCHAIN_H
