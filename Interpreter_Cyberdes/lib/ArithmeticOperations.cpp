// ArithmeticOperations.cpp
#include <stdexcept>
#include <variant>
#include "ArithmeticOperations.h" // Include the corresponding header file

void performArithmeticOperation(std::vector<std::variant<int, std::string>>& stack, 
                                const std::function<int(int, int)>& operation) {
    if (stack.size() < 2) {
        throw std::runtime_error("Not enough elements in stack for arithmetic operation");
    }

    auto var_b = stack.back(); stack.pop_back();
    auto var_a = stack.back(); stack.pop_back();

    // Check if both a and b are ints
    if (std::holds_alternative<int>(var_a) && std::holds_alternative<int>(var_b)) {
        int a = std::get<int>(var_a);
        int b = std::get<int>(var_b);

        stack.push_back(operation(a, b));
    } else {
        throw std::runtime_error("Arithmetic operation requires numeric operands");
    }
}