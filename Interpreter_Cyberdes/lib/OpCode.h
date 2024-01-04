// OpCode.h
#ifndef OPCODE_H
#define OPCODE_H

#include <string>

enum OpCode {
    STOP,
    ///////////////////////
    //Arithmetic Operations
    ADD,
    PUSH,
    SUB,
    MUL,
    DIV,
    ///////////////////////
    //Logic Operations
    EQ,
    LT,
    GT,
    AND,
    OR,
    NOT,
    ///////////////////////
    //Jumper Operations
    JUMP,
    JUMPI,
    ///////////////////////

    UNKNOWN
};

// Function to convert string to OpCode
OpCode getOpCode(const std::string& op);

#endif // OPCODE_H
