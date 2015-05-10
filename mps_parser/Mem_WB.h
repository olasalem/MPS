#pragma once
#include <string>
using namespace std;
class Mem_WB
{
public:
	Mem_WB();
	void Read_Result(int &R1,int &R2,int &R3){
		R1 = Reg_Result;
		R2 = Mem_Result;
		R3 = Reg_destination;
	}
	void Set_Result(int R1=0,int R2=0,int R3=0){
		Reg_Result = R1;
		Mem_Result = R2;
		Reg_destination = R3;
		if (Reg_Result==0)
			WBReg = 1;
		if (Mem_Result == 0)
			WBMem = 1;
	}
	~Mem_WB();
	int Mem_Result, Reg_Result;      // results to be saved in the Reg file and the Data memory
	int Reg_destination;            // stores the Destination Reg
	bool WBReg, WBMem;             // write enables for the reg file and data memory
private:
	
};