// LogicOperations.cpp
#include "LogicOperations.h"
#include <stdexcept>
#include <variant>

void performLogicOperation(std::vector<std::variant<unsigned int, int, std::string>>& stack, 
                           const std::function<int(int, int)>& operation) {
    if (stack.size() < 2) {
        throw std::runtime_error("Not enough elements in stack for logic operation");
    }

    auto var_b = stack.back(); stack.pop_back();
    auto var_a = stack.back(); stack.pop_back();

    // Check if both a and b are floats for the operation
    if (std::holds_alternative<int>(var_a) && std::holds_alternative<int>(var_b)) {
        int a = std::get<int>(var_a);
        int b = std::get<int>(var_b);

        // Perform the operation and push the result back as a float
        stack.push_back(operation(a, b));
    } else {
        throw std::runtime_error("Logic operation requires numeric operands");
    }
}
