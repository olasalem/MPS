#ifndef CPU_H
#define CPU_H

#include "regfile.h"
#include "DataMem.h"
#include "instruction.h"
#include "controlunit.h"
#include "IDec_Exec.h"
#include "IExec_Mem.h"
#include "IF_ID.h"
#include "Mem_WB.h"
#include "stack.h"
#include <QVector>

class CPU{
private:
    DataMem MyMem;
public:
    RegFile MyReg;
    ControlUnit MyCU;
    QVector<Instruction> MyIM;
    Ifetch_Decode buffer1;
    IDec_Exec buffer2;
    IExec_Mem buffer3;
    Mem_WB buffer4;
    Stack st;
    Instruction current;
    int PC_p; // take pc
    int result = 0, result2 = 0;
    int Mem_res;

    CPU();
    CPU(const QVector<Instruction>& v);
    ~CPU();
    Instruction Current();
    void ALU();
    void ALU2();
    void Up_PC();
    void Update_buffer1(Instruction m);
    void Update_buffer2();
    void Update_buffer3();
    void Update_buffer4();
    void Up_Memory();
    void Up_Reg();
    void Execute();
    void Forwarding();

};
#endif // CPU_H
