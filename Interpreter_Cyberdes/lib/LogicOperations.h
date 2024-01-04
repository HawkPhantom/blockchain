// LogicOperations.h
#ifndef LOGIC_OPERATIONS_H
#define LOGIC_OPERATIONS_H

#include <variant>
#include <vector>
#include <string>
#include <functional>

void performLogicOperation(std::vector<std::variant<int, std::string>>& stack, 
                           const std::function<int(int, int)>& operation);

#endif // LOGIC_OPERATIONS_H
