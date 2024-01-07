#include "SortCharacters.h"
#include <algorithm>
#include <sstream>

std::string sortCharacters(const std::string& data) {
    // Assuming data is a string representation of JSON
    std::string jsonData = data;

    // Sort the characters in the string
    std::sort(jsonData.begin(), jsonData.end());

    return jsonData;
}
