#include "OpCode.h"

OpCode getOpCode(const std::string& op) {
    //Arithmetic Operations
    if (op == "STOP") return STOP;
    if (op == "ADD") return ADD;
    if (op == "PUSH") return PUSH;
    if (op == "SUB") return SUB;
    if (op == "MUL") return MUL;
    if (op == "DIV") return DIV;
    if (op == "SDIV") return SDIV;
    if(op == "MOD") return MOD;
    if (op == "ADDMOD") return ADDMOD;
    if (op == "MULMOD") return MULMOD;
    if (op == "SMOD") return SMOD;
    if (op == "EXP") return EXP;
    if (op == "POP") return POP;
    //Logic Operations
    if (op == "EQ") return EQ;
    if (op == "LT") return LT;
    if (op == "GT") return GT;
    if (op == "AND") return AND;
    if (op == "OR") return OR;
    if (op == "NOT") return NOT;
    if (op == "XOR") return XOR;
    if (op == "isZero") return isZero;
    if (op == "BYTE") return BYTE;
    if (op == "SHL") return SHL;
    if (op == "SHR") return SHR;
    if (op == "PC") return PC;
    //Jumper Operations
    if (op == "JUMP") return JUMP;
    if (op == "JUMPI") return JUMPI;

    
    return UNKNOWN;
}