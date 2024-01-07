#include "CalculateBlockTargetHash.h"
#include <gmp.h>
#include <sstream>
#include <iomanip>

std::string CalculateBlockTargetHash::calculate(const Block& lastBlock) {
    const unsigned int HASH_LENGTH = 64;

    mpz_t maxValue;
    mpz_init(maxValue);
    
    mpz_ui_pow_ui(maxValue, 16, HASH_LENGTH); // 16^HASH_LENGTH
    mpz_sub_ui(maxValue, maxValue, 1); // maxValue - 1

    // Divide by difficulty
    unsigned long long difficulty = lastBlock.getHeaders().difficulty;
    if (difficulty == 0) difficulty = 1; // Prevent division by zero

    mpz_t targetValue;
    mpz_init(targetValue);
    mpz_div_ui(targetValue, maxValue, difficulty);

    // Convert to string
    char* targetStr = mpz_get_str(NULL, 16, targetValue);
    std::string targetHash(targetStr);
    
    // Free memory
    mpz_clear(maxValue);
    mpz_clear(targetValue);
    free(targetStr);

    // Ensure HASH_LENGTH
    if (targetHash.length() > HASH_LENGTH) {
        targetHash = std::string(HASH_LENGTH, 'f');
    } else if (targetHash.length() < HASH_LENGTH) {
        targetHash = std::string(HASH_LENGTH - targetHash.length(), '0') + targetHash;
    }

    return targetHash;
}