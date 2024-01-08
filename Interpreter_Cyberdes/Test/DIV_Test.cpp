#include "../lib/Interpreter.h"
#include <iostream>
#include <variant>

int main() {
    // Let's test for 4+8, here is our list of instructions
    std::vector<std::string> code = {"PUSH", "8", "PUSH", "4", "DIV", "STOP"};

    // Create an interpreter 
    Interpreter interpreter;

    // Run the code
    interpreter.runCode(code);

    // Get the last value from the stack
    auto lastValue = interpreter.getLastStackValue();

    // If the last value is an int, print it
    if (std::holds_alternative<int>(lastValue)) {
        std::cout << "Last Stack Value (int): " << std::get<int>(lastValue) << std::endl;
    } 
    else if (std::holds_alternative<unsigned int>(lastValue)) {
        std::cout << "Last Stack Value (unsigned int): " << std::get<unsigned int>(lastValue) << std::endl;
    } 
    // If the last value is a string, print it 
    else if (std::holds_alternative<std::string>(lastValue)) {
        std::cout << "Last Stack Value (string): " << std::get<std::string>(lastValue) << std::endl;
    }
    return 0;
}
