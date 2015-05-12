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
#include <QPair>
class CPU{

public:
    CPU();
    CPU(QVector<Instruction>& v);
    void setFile(QVector<Instruction>& v);
    RegFile MyReg;
    ControlUnit MyCU;
    QVector<Instruction> MyIM;
    Ifetch_Decode buffer1;
    IDec_Exec buffer2;
    IExec_Mem buffer3;
    Mem_WB buffer4;
    Stack st;
    Instruction current;
    DataMem MyMem;
    int PC_p; // take pc
    int result = 0, result2 = 0;
    int Mem_res;
    QVector< QPair<int,int> > Units; // The one that saves that units in every cycle , Units.first = unit{1,2,etc } , Units.second = cycle
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
    bool Forwarding();

};

#endif
