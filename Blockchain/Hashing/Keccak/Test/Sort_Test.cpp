#include <iostream>
#include "../lib/sortCharacters.h"

int main() {
    // Test data
    std::string jsonData = R"({"name":"John", "age":30, "city":"New York"})";

    // Call the sortCharacters function
    std::string sortedData = sortCharacters(jsonData);

    // Output the result
    std::cout << "Original JSON string: " << jsonData << std::endl;
    std::cout << "Sorted JSON string: " << sortedData << std::endl;

    return 0;
}
