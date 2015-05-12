#ifndef CPU_H
#define CPU_H

#include "regfile.h"
#include "DataMem.h"
#include "inst.h"
#include "controlunit.h"
#include "IDec_Exec.h"
#include "IExec_Mem.h"
#include "IF_ID.h"
#include "Mem_WB.h"
#include "stack.h"
#include <QVector>
#include <QPair>
class CPU{
private:
    DataMem MyMem;
    //regfile MyReg;
public:
    regfile MyReg;
    ControlUnit MyCU;
    QVector<inst> MyIM;
    Ifetch_Decode buffer1;
    IDec_Exec buffer2;
    IExec_Mem buffer3;
    Mem_WB buffer4;
    stack st;
    inst current;
    int PC_p; // take pc
    int result = 0, result2 = 0;
    int Mem_res;
    QVector< QPair<int,int> > Units; // The one that saves that units in every cycle , Units.first = unit{1,2,etc } , Units.second = cycle
    CPU();
    CPU(const QVector<inst>& v);
    ~CPU();
    inst Current();
    void ALU();
    void ALU2();
    void Up_PC();
    void Update_buffer1(inst m);
    void Update_buffer2();
    void Update_buffer3();
    void Update_buffer4();
    void Up_Memory();
    void Up_Reg();
    void Execute();
    bool Forwarding();

};

#endif
