#ifndef IF_ID
#define IF_ID

#include "instruction.h"

class Ifetch_Decode
{
public:
    Ifetch_Decode(){}
    Ifetch_Decode(const Instruction& t){
        Curr_Instruction = t;
        BranchTaken = false;
    }
    ~Ifetch_Decode(){}
    Instruction Curr_Instruction;
    int PC;
    bool BranchTaken;
};

#endif // IF_ID

