#include "../lib/Interpreter.h"
#include <iostream>
#include <variant>

int main() {
    // let's test for mod operation
    std::vector<std::string> code = {"PUSH", "8", "PUSH", "6", "PUSH", "5", "MULMOD", "STOP"};

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

    // If the last value is an unsigned int, print it
    else if (std::holds_alternative<unsigned int>(lastValue)) {
        std::cout << "Last Stack Value (unsigned int): " << std::get<unsigned int>(lastValue) << std::endl;
    }
    // If the last value is a string, print it 
    else if (std::holds_alternative<std::string>(lastValue)) {
        std::cout << "Last Stack Value (string): " << std::get<std::string>(lastValue) << std::endl;
    }
    return 0;
}
