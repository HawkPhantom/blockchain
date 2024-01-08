// LogicOperations.h
#ifndef LOGIC_OPERATIONS_H
#define LOGIC_OPERATIONS_H

#include <variant>
#include <vector>
#include <string>
#include <functional>

void performLogicOperation(std::vector<std::variant<unsigned int, int, size_t, std::string>>& stack, 
                           const std::function<int(int, int)>& operation);

void isZeroOperation(std::vector<std::variant<unsigned int, int, size_t, std::string>>& stack);
void shlOperation(std::vector<std::variant<unsigned int, int, size_t, std::string>>& stack);
void shrOperation(std::vector<std::variant<unsigned int, int, size_t, std::string>>& stack);

#endif // LOGIC_OPERATIONS_H
