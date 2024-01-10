#ifndef BLOCKHEADERS_H
#define BLOCKHEADERS_H

#include <string>
#include <sstream>
#include <iostream>

struct BlockHeaders {
    std::string parentHash;
    std::string beneficiary;
    uint64_t difficulty;
    uint64_t number;
    std::string timestamp;
    uint64_t nonce;

    std::string toString() const {
        std::ostringstream oss;
        oss << parentHash << beneficiary << difficulty << number << timestamp;
        return oss.str();
    }
};


#endif // BLOCKHEADERS_H
