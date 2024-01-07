#include "HeadersConverter.h"
#include <iostream>

BlockHeaders convertToBlockHeaders(const std::map<std::string, std::string>& genesisData) {
    BlockHeaders headers;
    auto it = genesisData.find("parentHash");
    if (it != genesisData.end()) {
        headers.parentHash = it->second;
    }

    it = genesisData.find("beneficiary");
    if (it != genesisData.end()) {
        headers.beneficiary = it->second;
    }

    it = genesisData.find("difficulty");
    if (it != genesisData.end()) {
        headers.difficulty = std::stoull(it->second);
    }

    it = genesisData.find("number");
    if (it != genesisData.end()) {
        headers.number = std::stoull(it->second);
    }

    it = genesisData.find("timestamp");
    if (it != genesisData.end()) {
        headers.timestamp = it->second;
    }

    it = genesisData.find("nonce");
    if (it != genesisData.end()) {
        headers.nonce = std::stoull(it->second);
    }

    std::cout << "parentHash: " << headers.parentHash << std::endl;
    std::cout << "beneficiary: " << headers.beneficiary << std::endl;

    return headers;
}
