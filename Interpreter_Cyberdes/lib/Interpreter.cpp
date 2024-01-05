#include "Interpreter.h"
#include "ArithmeticOperations.h"
#include "StackOperations.h"
#include "LogicOperations.h"
#include <iostream>
#include <stdexcept>
#include "Utility.h"

Interpreter::Interpreter() : programCounter(0) {}

void Interpreter::runCode(const std::vector<std::string>& code) {
    this->code = code;
    
    while (programCounter < code.size()) {
        OpCode opCode = getOpCode(code[programCounter]);

        try {
            std::cout << "OpCode: " << opCodeToString(opCode) << ", Stack Size: " << stack.size() << std::endl;
            switch (opCode) {
            case STOP:
                return;  // Normal termination

            case PUSH:
                programCounter++;
                if (isNumber(code[programCounter])) {
                    stack.push_back(std::stoi(code[programCounter]));
                } else {
                    stack.push_back(code[programCounter]);
                }
                break;

            case ADD:
                performArithmeticOperation(stack, [](int a, int b) { return a + b; });
                break;

            case SUB:
                performArithmeticOperation(stack, [](int a, int b) { return a - b; });
                break;

            case MUL:
                performArithmeticOperation(stack, [](int a, int b) { return a * b; });
                break;

            case DIV:
                performArithmeticOperation(stack, [](int a, int b) {
                    if (b == 0) throw std::runtime_error("Division by zero");
                    return a / b;
                });
                break;

            case EQ:
                performLogicOperation(stack, [](int a, int b) { return a == b; });
                break;

            case LT:
                performLogicOperation(stack, [](int a, int b) { return a < b; });
                break;

            case GT:
                performLogicOperation(stack, [](int a, int b) { return a > b; });
                break;

            case AND:
                performLogicOperation(stack, [](int a, int b) { return a && b; });
                break;

            case OR:
                performLogicOperation(stack, [](int a, int b) { return a || b; });
                break;

            case NOT:
                performLogicOperation(stack, [](int a, int b) { return !a; });
                break;

            case JUMP:
                handleJump(*this);
                continue;

            case JUMPI:
              {
                int newCounter = handleJumpI(*this);
                if (newCounter != -1) {
                    programCounter = newCounter;
                } else {
                    programCounter++;
                }
                continue;
              }

            default:
                throw std::runtime_error("Unknown OpCode");
            }
        } catch (const std::runtime_error& error) {
            std::cout << error.what() << std::endl;
            return;
        }

        programCounter++;
    }
}

std::variant<int, std::string> Interpreter::getLastStackValue() const {
    if (!stack.empty()) {
        return stack.back();
    }
    return 0; // Default integer value
}
