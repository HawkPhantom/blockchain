// ArithmeticOperations.cpp
#include <stdexcept>
#include <variant>
#include "ArithmeticOperations.h" // Include the corresponding header file

void performArithmeticOperation(std::vector<std::variant<unsigned int, int, std::string>>& stack, 
                                const std::function<int(int, int)>& operation) {
    if (stack.size() < 2) {
        throw std::runtime_error("Not enough elements in stack for arithmetic operation");
    }

    auto var_b = stack.back(); stack.pop_back();
    auto var_a = stack.back(); stack.pop_back();

    // Convert operands to int if either is unsigned int
    if((std::holds_alternative<int>(var_a) && std::holds_alternative<int>(var_b)) || (std::holds_alternative<unsigned int>(var_a) && std::holds_alternative<unsigned int>(var_b))){
        int a = std::holds_alternative<int>(var_a) ? std::get<int>(var_a) : static_cast<int>(std::get<unsigned int>(var_a));
        int b = std::holds_alternative<int>(var_b) ? std::get<int>(var_b) : static_cast<int>(std::get<unsigned int>(var_b));
        
        stack.push_back(operation(a, b));
    }
    else{
        throw std::runtime_error("Arithmetic operation requires numeric operands");
    }
    
}


void performArithmeticOperation_threeInput (std::vector<std::variant<unsigned int, int, std::string>>& stack, 
                                            const std::function<int(int, int, int)>& operation) {
    if (stack.size() < 3) {
        throw std::runtime_error("Not enough elements in stack for arithmetic operation");
    }

    auto var_c = stack.back(); stack.pop_back();
    auto var_b = stack.back(); stack.pop_back();
    auto var_a = stack.back(); stack.pop_back();

    // Check if all a, b and c are ints
    if ((std::holds_alternative<int>(var_a) && std::holds_alternative<int>(var_b) && std::holds_alternative<int>(var_c)) || (std::holds_alternative<unsigned int>(var_a) && std::holds_alternative<unsigned int>(var_b) && std::holds_alternative<unsigned int>(var_c))) {
        int a = std::holds_alternative<int>(var_a) ? std::get<int>(var_a) : static_cast<int>(std::get<unsigned int>(var_a));
        int b = std::holds_alternative<int>(var_b) ? std::get<int>(var_b) : static_cast<int>(std::get<unsigned int>(var_b));
        int c = std::holds_alternative<int>(var_c) ? std::get<int>(var_c) : static_cast<int>(std::get<unsigned int>(var_c));

        stack.push_back(operation(a, b, c));
    } 
    
    else {
        throw std::runtime_error("Arithmetic operation requires numeric operands");
    }
}

void performUnsignedArithmeticOperation(std::vector<std::variant<unsigned int, int, std::string>>& stack, 
                                        const std::function<unsigned int(unsigned int, unsigned int)>& operation) {
    if (stack.size() < 2) {
        throw std::runtime_error("Not enough elements in stack for arithmetic operation");
    }

    auto var_b = stack.back(); stack.pop_back();
    auto var_a = stack.back(); stack.pop_back();

    // Check if both a and b are ints
    if (std::holds_alternative<unsigned int>(var_a) && std::holds_alternative<unsigned int>(var_b)) {
        unsigned int a = std::get<unsigned int>(var_a);
        unsigned int b = std::get<unsigned int>(var_b);

        stack.push_back(operation(a, b));
    } else {
        throw std::runtime_error("Arithmetic operation requires numeric operands");
    }
}

void performUnsignedArithmeticOperation_threeInput(std::vector<std::variant<unsigned int, int, std::string>>& stack, 
                                                   const std::function<unsigned int(unsigned int, unsigned int, unsigned int)>& operation) {
    if (stack.size() < 3) {
        throw std::runtime_error("Not enough elements in stack for arithmetic operation");
    }

    auto var_c = stack.back(); stack.pop_back();
    auto var_b = stack.back(); stack.pop_back();
    auto var_a = stack.back(); stack.pop_back();

    // Check if all a, b and c are ints
    if (std::holds_alternative<unsigned int>(var_a) && std::holds_alternative<unsigned int>(var_b) && std::holds_alternative<unsigned int>(var_c)) {
        unsigned int a = std::get<unsigned int>(var_a);
        unsigned int b = std::get<unsigned int>(var_b);
        unsigned int c = std::get<unsigned int>(var_c);

        stack.push_back(operation(a, b, c));
    } else {
        throw std::runtime_error("Arithmetic operation requires numeric operands");
    }
}