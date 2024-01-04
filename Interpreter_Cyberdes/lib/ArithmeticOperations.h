// ArithmeticOperations.h
#ifndef ARITHMETIC_OPERATIONS_H
#define ARITHMETIC_OPERATIONS_H

#include <variant>
#include <vector>
#include <string>
#include <functional>

void performArithmeticOperation(std::vector<std::variant<int, std::string>>& stack, 
                                const std::function<int(int, int)>& operation);

#endif // ARITHMETIC_OPERATIONS_H
