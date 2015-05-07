#include "controlunit.h"


ControlUnit::ControlUnit()
{
}
void ControlUnit::Reset()
{
    RegDst = false;
    Branch = false;
    MemRead = false;
    MemtoReg = false;
    MemWrite = false;
    ALUSrc = false;
    RegWrite = false;
    ALUOp = 0;
}
void ControlUnit::Set(bool t1 = false, bool t2 = false, bool t3 = false, bool t4 = false, bool t5 = false, bool t6 = false, bool t7 = false, int t8 = 0)
{
    RegDst = t1;
    Branch = t2;
    MemRead = t3;
    MemtoReg = t4;
    MemWrite = t5;
    ALUSrc = t6;
    RegWrite = t7;
    ALUOp = t8;
}
ControlUnit::~ControlUnit()
{
}
