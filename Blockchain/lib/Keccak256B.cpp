#include "Keccak256B.h"
#include "SortCharacters.h"  // Include the header for the sortCharacters function
#include <cryptopp/sha3.h>
#include <cryptopp/hex.h>

std::string Keccak256::hash(const std::string& input) {
    // Sort the input string first
    std::string sortedInput = sortCharacters(input);

    CryptoPP::SHA3_256 hash;
    std::string digest;

    CryptoPP::StringSource s(sortedInput, true, 
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest)
            )
        )
    );

    return digest;
}
