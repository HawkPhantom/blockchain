// Utility.cpp
#include "Utility.h"
#include <cctype>
#include <algorithm>
#include "OpCode.h"

bool isNumber(const std::string& str) {
    bool decimalPoint = false;
    for (char const &c : str) {
        if (std::isdigit(c) || (c == '.' && !decimalPoint)) {
            if (c == '.') {
                decimalPoint = true;
            }
            continue;
        }
        return false;
    }
    return true;
}

std::string opCodeToString(OpCode opCode) {
    switch (opCode) {
        case STOP: return "STOP";
        case PUSH: return "PUSH";
        case ADD: return "ADD";
        case SUB: return "SUB";
        case MUL: return "MUL";
        case DIV: return "DIV";
        case EQ: return "EQ";
        case LT: return "LT";
        case GT: return "GT";
        case AND: return "AND";
        case OR: return "OR";
        case NOT: return "NOT";
        case JUMP: return "JUMP";
        case JUMPI: return "JUMPI";
        default: return "Unknown OpCode";
    }
}
