
#ifndef arch_CPU_h
#define arch_CPU_h
#include "regfile.h"
#include "DataMem.h"
#include "inst.h"
#include "controlunit.h"
#include "IDec_Exec.h"
#include "IExec_Mem.h"
#include "IF_ID.h"
#include "Mem_WB.h"

class CPU{
private:
    DataMem MyMem;
    regfile MyReg;
public:
    ControlUnit MyCU;
    QVector<inst> MyIM;
    Ifetch_Decode buffer1;
    IDec_Exec buffer2;
    IExec_Mem buffer3;
    Mem_WB buffer4;
    inst current;
    int PC; // take pc
    int result, result2;
    int Mem_res;

    CPU();
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

};

#endif
