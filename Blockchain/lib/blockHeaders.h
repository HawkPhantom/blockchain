#ifndef BLOCKHEADERS_H
#define BLOCKHEADERS_H

#include <string>

struct BlockHeaders {
    std::string parentHash;
    std::string beneficiary;
    uint64_t difficulty;
    uint64_t number;
    std::string timestamp;
    uint64_t nonce;
};

#endif // BLOCKHEADERS_H
