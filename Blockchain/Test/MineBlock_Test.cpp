#include <iostream>
#include <cassert>
#include "Block.h"
#include "../lib/Block.h"
#include "../lib/Blockchain.h"
#include "../lib/CalculateBlockTargetHash.h"

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

    // Calculate and print the target hash for the block
    std::string targetHash = CalculateBlockTargetHash::calculate(block);
    std::cout << "Target Hash: " << targetHash << std::endl;
}

int main() {
    // Initialize a blockchain with a genesis block
    Blockchain blockchain;

    // Get the last block (genesis block) from the blockchain
    const Block& lastBlock = blockchain.getLatestBlock();

    // Define a beneficiary address for mining the new block
    std::string beneficiary = "0xYourBeneficiaryAddress";

    // Print the last block
    std::cout << "Last Block: " << std::endl;
    printBlock(lastBlock);

    // Mine a new block
    Block newBlock = Block::mineBlock(lastBlock, beneficiary);

    // Print the new block
    std::cout << "New Block Mined!" << std::endl;
    std::cout << "New Block: " << std::endl;
    printBlock(newBlock);

    // Calculate the target hash for the new block
    std::string targetHash = CalculateBlockTargetHash::calculate(newBlock);

    // Print the target hash
    std::cout << "Target Hash: " << targetHash << std::endl;

    // Print new block details
    printBlock(newBlock);

    // Test 1: Check if the new block's parent hash matches the last block's hash
    // In main function of your test code
    assert(newBlock.getHeaders().parentHash == Keccak256::hash(lastBlock.getHeaders().toString()));

    // Test 2: Check if the new block's hash is less than or equal to the target hash
    assert(CalculateBlockTargetHash::calculate(newBlock) <= targetHash);

    // Test 3: Check if the block number is correctly incremented
    assert(newBlock.getHeaders().number == lastBlock.getHeaders().number + 1);

    // Additional tests can be added as needed

    std::cout << "All tests passed for mineBlock function!" << std::endl;

    return 0;
}

