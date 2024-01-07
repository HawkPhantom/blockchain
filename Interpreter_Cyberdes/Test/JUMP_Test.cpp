#include "../lib/Interpreter.h"
#include <iostream>
#include <variant>

int main() {
    // explain the code in one sentence
    //This code will jump to the 6th instruction, then print "jump successful" and stop.
    std::vector<std::string> code = {"PUSH", "6", "JUMP", "PUSH", "0", "JUMP", "PUSH", "jump successful", "STOP"};
    
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
