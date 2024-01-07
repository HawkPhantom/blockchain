#ifndef HEADERSCONVERTER_H
#define HEADERSCONVERTER_H

#include <map>
#include <string>
#include "BlockHeaders.h" // Include your BlockHeaders definition here

BlockHeaders convertToBlockHeaders(const std::map<std::string, std::string>& genesisData);

#endif // HEADERSCONVERTER_H
