#include "../lib/Interpreter.h"
#include <iostream>
#include <variant>

int main() {
    // Test code with JUMPI operation and a condition of '0' (false)
    std::vector<std::string> code = {"PUSH", "4", "PUSH", "8", "ADD", "STOP"};

    Interpreter interpreter;
    interpreter.runCode(code);

    auto lastValue = interpreter.getLastStackValue();
    if (std::holds_alternative<int>(lastValue)) {
        std::cout << "Last Stack Value (int): " << std::get<int>(lastValue) << std::endl;
    } else if (std::holds_alternative<std::string>(lastValue)) {
        std::cout << "Last Stack Value (string): " << std::get<std::string>(lastValue) << std::endl;
    }

    return 0;
}
