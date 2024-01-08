#ifndef KECCAK256B_H
#define KECCAK256B_H

#include <string>

class Keccak256 {
public:
    static std::string hash(const std::string& input);
};

#endif // KECCAK256_H