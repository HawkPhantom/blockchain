// Interpreter.h
#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <variant>
#include <vector>
#include <string>
#include "OpCode.h"

class Interpreter {
public:
    Interpreter();

    friend void handleJump(Interpreter& interpreter);
    friend int handleJumpI(Interpreter& interpreter);
    
    void runCode(const std::vector<std::string>& code);
    std::variant<int, std::string> getLastStackValue() const;

private:
    std::vector<std::string> code;
    std::vector<std::variant<int, std::string>> stack;
    size_t programCounter;
};

#endif // INTERPRETER_H
