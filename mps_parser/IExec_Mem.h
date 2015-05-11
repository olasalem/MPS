#pragma once
#include <string>
using namespace std;
class IExec_Mem
{
public:
	IExec_Mem();
	~IExec_Mem();
	bool WBReg, WBMem;          // write enables for the reg file and data memory
	bool ReadMem;
	int Res_Alu;           // stores the result from the ALY
	int Reg_destination;         // stores the Destination Reg
	int PC;
};
