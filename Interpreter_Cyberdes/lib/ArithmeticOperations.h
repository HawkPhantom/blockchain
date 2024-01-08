// ArithmeticOperations.h
#ifndef ARITHMETIC_OPERATIONS_H
#define ARITHMETIC_OPERATIONS_H

#include <variant>
#include <vector>
#include <string>
#include <functional>

void performArithmeticOperation(std::vector<std::variant<unsigned int, int, std::string>>& stack, 
                                const std::function<int(int, int)>& operation);

void performArithmeticOperation_threeInput (std::vector<std::variant<unsigned int, int, std::string>>& stack, 
                                            const std::function<int(int, int, int)>& operation);

void performUnsignedArithmeticOperation(std::vector<std::variant<unsigned int, int, std::string>>& stack, 
                                        const std::function<unsigned int(unsigned int, unsigned int)>& operation);

void performUnsignedArithmeticOperation_threeInput(std::vector<std::variant<unsigned int, int, std::string>>& stack, 
                                                   const std::function<unsigned int(unsigned int, unsigned int, unsigned int)>& operation);

#endif // ARITHMETIC_OPERATIONS_H
