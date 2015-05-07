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
		WBReg = false;
		WBMem = false;
	}
	void Read_Regs(int &R1, int &R2, int &R3, int &R4,bool &WB1 , bool &WB2){
		R1 = Rs;
		R2 = RtReg;
		R3 = RtImm;
		R4 = Rd;
		WB1 = WBReg;
		WB2 = WBMem;
	}
	void Set_Regs(int R1, int R2, int R3, int R4){
		Rs = R1;
		RtReg = R2;
		RtImm = R3;
		Rd = R4;
	}
	~IDec_Exec();
	int Rs, RtReg, RtImm, Rd;         // the four registers that result from the decoding
	bool WBReg, WBMem;           // write enables for the reg file and data memory
private:
};