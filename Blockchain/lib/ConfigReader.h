#ifndef CONFIGREADER_H
#define CONFIGREADER_H

#include <string>
#include <map>

std::map<std::string, std::string> readGenesisConfig(const std::string& filename);

#endif // CONFIGREADER_H
