#ifndef MEM_WB
#define MEM_WB

class Mem_WB
{
public:
    Mem_WB():BT(false){}
    ~Mem_WB(){}
    int Mem_Result, Alu_Result;      // results to be saved in the Reg file and the Data memory
    int Reg_destination;            // stores the Destination Reg
    bool WBReg;
    bool MemtoReg;             // write enables for the reg file and data memory
    bool BT;
};
#endif // MEM_WB

