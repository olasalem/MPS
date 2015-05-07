#pragma once
#include <string>
using namespace std;
class IExec_Mem
{
public:
	IExec_Mem();
	~IExec_Mem();
	void Read_Result(int &R1,int &R2){
		R1 = Res_Alu;
		R2 = Reg_destination;
	}
	void Set_Result(int R1,int R2){
		Res_Alu = R1;
		Reg_destination = R2;
		WBReg = WBMem = 1;
	}
	bool WBReg, WBMem;          // write enables for the reg file and data memory
	int Res_Alu;           // stores the result from the ALY
	int Reg_destination;         // stores the Destination Reg
private:
	
};