#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include "IDec_Exec.h"
#include "IExec_Mem.h"
#include "Mem_WB.h"
#include "inst.h"
class ControlUnit
{
public:
    ControlUnit();
    void Set(inst );  // to set the signals, create an object of buffer 1 , Send the The instruction that exists in this buffer to this function
    void Reset();
    ~ControlUnit();
   // int Get_Type(inst);
    bool RegDst, Branch, MemRead, MemtoReg, MemWrite, ALUSrc, RegWrite,Jump;
    int ALUOp;
    
};
/* void Forwarding()
    {
        if (buff1.Rs == buff2.Reg_destination)
            reg[Rs] = buff2.Reg_destination;
        if (buff1.RtReg == buff2.Reg_destination)
            reg[RtReg] = buff2.Reg_destination;
        if (buff1.Rs == buff3.Reg_destination)
            reg[Rs] = buff3.Reg_destination;
        if (buff1.RtReg == buff3.Reg_destination)
            reg[RtReg] = buff3.Reg_destination;

    }
*/
/* void Stalling(){
    if (buff1.Rs == buff2.Reg_destination && MemRead)
            wait(200);
    if (buff1.Rs == buff3.Reg_destination && MemRead)
            wait(200);
    if (buff1.RtReg == buff2.Reg_destination && MemRead)
            wait(200);
    if (buff1.RtReg == buff3.Reg_destination && MemRead)
            wait(200);
}
*/
/* LW-SW data hazard
    if(MemRead && buff1.Rs == buff2.Reg_destination && buff3.WBMem)

*/
/*
Branch stalling
*/


#endif // CONTROLUNIT_H
