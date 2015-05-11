#pragma once
#include <string>
using namespace std;
class IDec_Exec
{
public:
	IDec_Exec(){
		Rs = 0;
		RtReg = 0;
		RtImm = 0;
		Rd = 0;
		Rs_Value = 0;
		Rt_Value =0;
		WBReg = false;
		MemWrite = MemRead = false;
	}
	~IDec_Exec();
	int Rs, RtReg, RtImm, Rd;         // the four registers that result from the decoding
	int Rs_Value,Rt_Value;
	bool WBReg;
	bool MemWrite;         // == WBMem // write enables for the data memory
	bool MemRead;     // == MemtoReg // to read from memory to reg (LW)
	bool Branch; 
	bool AluSrc;
	int AluOP;
	int PC;
};
