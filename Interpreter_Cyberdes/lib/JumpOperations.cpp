// JumpOperations.cpp
#include "JumpOperations.h"
#include <stdexcept>
#include <variant>

void handleJump(Interpreter& interpreter) {
    if (interpreter.stack.size() < 1) {
        throw std::runtime_error("Insufficient elements on stack for JUMP");
    }
    
    auto destination = std::get<int>(interpreter.stack.back());
    interpreter.stack.pop_back(); // Pop the destination off the stack

    if (destination < 0) {
        throw std::runtime_error("JUMP destination cannot be negative");
    }
    if (static_cast<size_t>(destination) >= interpreter.code.size()) {
        throw std::runtime_error("JUMP destination exceeds code size");
    }
    if (static_cast<int>(destination) == interpreter.programCounter) {
        throw std::runtime_error("JUMP to the current instruction is not allowed");
    }

    interpreter.programCounter = static_cast<int>(destination);
}


int handleJumpI(Interpreter& interpreter) {
    // Check for sufficient elements on the stack
    if (interpreter.stack.size() < 2) {
        throw std::runtime_error("Insufficient elements on stack for JUMPI");
    }

    // Retrieve condition and destination
    auto condition = interpreter.stack[interpreter.stack.size() - 2];
    auto destination = interpreter.stack.back();

    // Pop the destination and condition off the stack
    interpreter.stack.pop_back();
    interpreter.stack.pop_back();

    if (std::holds_alternative<int>(condition) && std::holds_alternative<int>(destination)) {
        auto destinationValue = std::get<int>(destination);
        
        // Check for negative destination or exceeding code size
        if (destinationValue < 0) {
            throw std::runtime_error("JUMPI destination cannot be negative");
        }
        if (static_cast<size_t>(destinationValue) >= interpreter.code.size()) {
            throw std::runtime_error("JUMPI destination exceeds code size");
        }
        // Prevent jumping to the current instruction
        if (static_cast<int>(destinationValue) == interpreter.programCounter) {
            throw std::runtime_error("JUMPI to the current instruction is not allowed");
        }

        // Perform the jump if the condition is true (non-zero)
        if (std::get<int>(condition) != 0) {
            return static_cast<int>(destinationValue); // Return new program counter value
        }
    } else {
        throw std::runtime_error("JUMPI operation requires numeric values");
    }

    return -1; // Indicate that program counter should be incremented normally
}



