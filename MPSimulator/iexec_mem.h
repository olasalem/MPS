#ifndef IEXEC_MEM
#define IEXEC_MEM

class IExec_Mem
{
public:
    IExec_Mem():BT(false){}
    ~IExec_Mem(){}
    bool WBReg;
    bool MemtoReg;          // MemRead
    bool MemWrite;          // WBMem
    int Res_Alu;           // stores the result from the ALY
    int Reg_destination;         // stores the Destination Reg
    int Branch;
    int PC;
    int Rt_Value;
    bool BT;
};

#endif // IEXEC_MEM

