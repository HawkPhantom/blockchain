#ifndef CALCULATE_BLOCK_TARGET_HASH_H
#define CALCULATE_BLOCK_TARGET_HASH_H

#include "Block.h"
#include <string>
#include <gmp.h>

class CalculateBlockTargetHash {
public:
    static std::string calculate(const Block& lastBlock);
};

#endif // CALCULATE_BLOCK_TARGET_HASH_H
