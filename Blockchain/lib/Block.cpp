#include "Block.h"
#include "CalculateBlockTargetHash.h"
#include <random>
#include <chrono>
#include <iostream>
#include <filesystem>

// Forward declaration
class Block;

// Implementation of Block methods

// Constructor
Block::Block(const BlockHeaders& headers) : blockHeaders(headers) {}

// Static method to mine a new block
Block Block::mineBlock(const Block& lastBlock, const std::string& beneficiary) {
    std::string target = CalculateBlockTargetHash::calculate(lastBlock);
    unsigned long long timestamp;
    std::string parentHash, header;
    unsigned long long nonce;
    const unsigned long long MAX_NONCE_VALUE = std::numeric_limits<unsigned long long>::max();
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::string underTargetHash;
    BlockHeaders truncatedBlockHeaders;

    // Do While
    do {
        timestamp = std::chrono::system_clock::now().time_since_epoch().count();
        parentHash = Keccak256::hash(lastBlock.getHeaders().parentHash);
        unsigned long long difficulty = lastBlock.getHeaders().difficulty + 1;
        unsigned long long number = lastBlock.getHeaders().number + 1;

        truncatedBlockHeaders.parentHash = parentHash;
        truncatedBlockHeaders.beneficiary = beneficiary;
        truncatedBlockHeaders.difficulty = difficulty;
        truncatedBlockHeaders.number = number;
        truncatedBlockHeaders.timestamp = timestamp;

        header = Keccak256::hash(parentHash + beneficiary + std::to_string(difficulty) + std::to_string(number) + std::to_string(timestamp));
        
        std::uniform_int_distribution<unsigned long long> distribution(0, MAX_NONCE_VALUE);
        nonce = distribution(generator);

        underTargetHash = Keccak256::hash(header + std::to_string(nonce));

        while (underTargetHash >= target) {
            nonce = distribution(generator);
            underTargetHash = Keccak256::hash(header + std::to_string(nonce));
        }

        truncatedBlockHeaders.nonce = nonce;

        return Block(truncatedBlockHeaders);
    } while (underTargetHash >= target);

    truncatedBlockHeaders.nonce = nonce;

    return Block(truncatedBlockHeaders);
}

