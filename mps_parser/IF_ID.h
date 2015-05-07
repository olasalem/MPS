#pragma once
#include <string>
using namespace std;
class Ifetch_Decode
{
public:
	Ifetch_Decode(string t){
		Curr_Instruction = t;
	}
	~Ifetch_Decode();
	string Curr_Instruction;
};