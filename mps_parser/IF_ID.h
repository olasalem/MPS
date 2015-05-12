#pragma once
#include <string>
#include "inst.h"
using namespace std;
class Ifetch_Decode
{
public:
    Ifetch_Decode(){}
    Ifetch_Decode(const inst& t){
		Curr_Instruction = t;
		BranchTaken = false;
	}
    ~Ifetch_Decode(){}
	inst Curr_Instruction;
	int PC;
	bool BranchTaken;
};
