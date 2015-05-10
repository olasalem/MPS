#pragma once
#include <string>
#include "Inst"
using namespace std;
class Ifetch_Decode
{
public:
	Ifetch_Decode(Inst t){
		Curr_Instruction = t;
	}
	~Ifetch_Decode();
	Inst Curr_Instruction;
};
