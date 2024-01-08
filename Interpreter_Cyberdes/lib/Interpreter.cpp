#include <iostream>
#include <stdexcept>
#include <math.h>
#include "Interpreter.h"
#include "ArithmeticOperations.h"
#include "StackOperations.h"
#include "LogicOperations.h"
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

            case PUSH0:
                stack.push_back(0);
                break;

            case PUSH:
                programCounter++;
                if (isNumber(code[programCounter])) {
                    // Determine if the number is signed or unsigned
                    if (code[programCounter][0] == '-') {
                        // Number is signed
                        stack.push_back(std::stoi(code[programCounter]));
                    } else {
                        // Number is unsigned
                        stack.push_back(static_cast<unsigned int>(std::stoul(code[programCounter])));
                    }
                } else {
                    stack.push_back(code[programCounter]);
                }
                break;

            case POP:
                if (stack.empty()) {
                    throw std::runtime_error("Stack is empty");
                }
                stack.pop_back();
                break;

            case ADD:
                performUnsignedArithmeticOperation(stack, [](unsigned int a, unsigned int b) { return a + b; });
                break;

            case SUB:
                performUnsignedArithmeticOperation(stack, [](unsigned int a, unsigned int b) { return a - b; });
                break;

            case MUL:
                performUnsignedArithmeticOperation(stack, [](unsigned int a, unsigned int b) { return a * b; });
                break;

            case DIV:
                performUnsignedArithmeticOperation(stack, [](unsigned int a, unsigned int b) {
                    if (b == 0) throw std::runtime_error("Division by zero");
                    return a / b;
                });
                break;

            case SDIV:
                //if a or be is unsigned, convert to signed
                performArithmeticOperation(stack, [](int a, int b) {
                    if (b == 0) throw std::runtime_error("Division by zero");
                    return a / b;
                });
                break;

            case MOD:
                performUnsignedArithmeticOperation(stack, [](unsigned int a, unsigned int b) {
                    if (b == 0) throw std::runtime_error("Division by zero");
                    return a % b;
                });
                break;

            case ADDMOD:
                performUnsignedArithmeticOperation_threeInput(stack, [](unsigned int a, unsigned int b, unsigned int c) {
                    if (b == 0) throw std::runtime_error("Division by zero");
                    return (a + b) % c;
                });
                break;
            
            case MULMOD:
                performUnsignedArithmeticOperation_threeInput(stack, [](unsigned int a, unsigned int b, unsigned int c) {
                    if (b == 0) throw std::runtime_error("Division by zero");
                    return (a * b) % c;
                });
                break;

            case SMOD: 
                performArithmeticOperation(stack, [](int a, int b) {
                    if (b == 0) throw std::runtime_error("Division by zero");
                    return a % b;
                });
                break;

            case isZero:
                isZeroOperation(stack);
                break;

            case EXP:
                performUnsignedArithmeticOperation(stack, [](unsigned int a, unsigned int b) { return pow(a, b); });
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

            case XOR:
                performLogicOperation(stack, [](int a, int b) { return a ^ b; });
                break;

            case BYTE: 
                performUnsignedArithmeticOperation(stack, [](unsigned int a, unsigned int b) {
                    if (b > 31) throw std::runtime_error("Byte operation requires second operand to be less than 32");
                    return (a >> (8 * b)) & 0xff;
                });
                break;
            
            case SHL:
                shlOperation(stack);
                break;
            
            case SHR:
                shrOperation(stack);
                break;

            case PC:
                stack.push_back(programCounter);
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

std::variant<unsigned int, int, size_t, std::string> Interpreter::getLastStackValue() const {
    if (!stack.empty()) {
        return stack.back();
    }
    return 0; // Default integer value
}
