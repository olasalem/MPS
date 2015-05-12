#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include "IDec_Exec.h"
#include "IExec_Mem.h"
#include "Mem_WB.h"
#include "instruction.h"
class ControlUnit
{
public:
    ControlUnit();
    void Set(Instruction);  // to set the signals, create an object of buffer 1 , Send the The instruction that exists in this buffer to this function
    void Reset();
    ~ControlUnit();
    bool RegDst, Branch, MemRead, MemtoReg, MemWrite, ALUSrc, RegWrite,Jump;
    int ALUOp;

};

#endif // CONTROLUNIT_H
