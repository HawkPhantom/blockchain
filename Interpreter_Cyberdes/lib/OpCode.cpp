#include "OpCode.h"

OpCode getOpCode(const std::string& op) {
    //Arithmetic Operations
    if (op == "STOP") return STOP;
    if (op == "ADD") return ADD;
    if (op == "PUSH") return PUSH;
    if (op == "SUB") return SUB;
    if (op == "MUL") return MUL;
    if (op == "DIV") return DIV;
    if(op == "MOD") return MOD;
    if (op == "ADDMOD") return ADDMOD;
    //Logic Operations
    if (op == "EQ") return EQ;
    if (op == "LT") return LT;
    if (op == "GT") return GT;
    if (op == "AND") return AND;
    if (op == "OR") return OR;
    if (op == "NOT") return NOT;
    if (op == "XOR") return XOR;
    //Jumper Operations
    if (op == "JUMP") return JUMP;
    if (op == "JUMPI") return JUMPI;

    
    return UNKNOWN;
}