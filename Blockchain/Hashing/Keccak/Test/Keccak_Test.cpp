#include <iostream>
#include "../lib/Keccak256B.h"

int main() {
    std::string input = "Hello, world!";
    std::string hash = Keccak256::hash(input);

    std::cout << "Input: " << input << std::endl;
    std::cout << "Keccak256 Hash: " << hash << std::endl;

    return 0;
}
