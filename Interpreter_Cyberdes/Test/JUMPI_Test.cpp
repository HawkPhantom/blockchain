#include "../lib/Interpreter.h"
#include <iostream>
#include <variant>

int main() {
    // Test code with JUMPI operation and a condition of '1' (true), it will jump to the 8th instruction, then print "jump successful" and stop.
    std::vector<std::string> code = {"PUSH", "1", "PUSH", "8", "JUMPI", "PUSH", "jump not successful", "STOP", "PUSH", "jump successful", "STOP"};

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
