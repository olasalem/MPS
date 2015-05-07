#pragma once
#include "IDec_Exec.h"
#include "IExec_Mem.h"
#include "Mem_WB.h"
class CntrlUnit
{
public:
	CntrlUnit();
	void Set(bool, bool , bool , bool, bool, bool, bool , int );
	void Reset();
	~CntrlUnit();
private:
	bool RegDst, Branch, MemRead, MemtoReg, MemWrite, ALUSrc, RegWrite;
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

