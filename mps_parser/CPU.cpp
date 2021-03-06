#include "CPU.h"
#include <QtDebug>

CPU::CPU(){}

CPU::~CPU(){}

/* NOT NEEDED
inst CPU::Current(){
    return MyIM[PC];
}
*/

void CPU::Up_PC()
{
    if(MyCU.Branch || MyCU.Jump)
        PC = result2;
    else
        PC++;
}

void CPU::Update_buffer1(inst m)
{
    buffer1.Curr_Instruction = m;
    buffer1.PC = PC;
    buffer1.BranchTaken = buffer2.BranchTaken;
}

// WE PROBABLY DON'T NEED PC, BRANCH AND JUMP CONTROLS IN THE BUFFERS ANYMORE
void CPU::Update_buffer2()
{
    buffer2.Rd = buffer1.Curr_Instruction.rd;
    buffer2.Rs = buffer1.Curr_Instruction.rs;
    buffer2.RtReg = buffer1.Curr_Instruction.rt;
    buffer2.Rs_Value = MyReg[buffer1.Curr_Instruction.rs];
    buffer2.RtImm = buffer1.Curr_Instruction.imm;
    buffer2.Rt_Value = MyReg[buffer1.Curr_Instruction.rt];
    buffer2.MemRead = MyCU.MemRead;
    if(buffer1.BranchTaken)
    {
        buffer2.MemWrite = false;
        buffer2.WBReg = false; //or memtoreg = 1 only if memread = 1
    }
    else
    {
        buffer2.MemWrite = MyCU.MemWrite;
        buffer2.WBReg = MyCU.RegWrite;
    }
    buffer2.PC = buffer1.PC;
    buffer2.AluSrc = MyCU.ALUSrc;
    buffer2.Branch = MyCU.Branch;
    buffer2.AluOP = MyCU.ALUOp;
    buffer2.RegDst = MyCU.RegDst;
}


void CPU::Update_buffer3()
{

    buffer3.Res_Alu = result;
    buffer3.MemtoReg = buffer2.MemRead;
    buffer3.WBReg = buffer2.WBReg;
    buffer3.PC = buffer2.PC;
    buffer3.Branch = buffer2.Branch;
    buffer3.MemWrite = buffer2.MemWrite;
    buffer3.Rt_Value = buffer2.Rt_Value;
    // MUX BEFORE BUFFER 3
    if(buffer2.RegDst)
       buffer3.Reg_destination = buffer2.RtReg;
    else
       buffer3.Reg_destination = buffer2.Rd;
}

void CPU::Update_buffer4()
{
    buffer4.Mem_Result = Mem_res;
    buffer4.Reg_destination = buffer3.Reg_destination;
    buffer4.Alu_Result = buffer3.Res_Alu;
    buffer4.MemtoReg = buffer3.MemtoReg;
    buffer4.WBReg = buffer3.WBReg;

}

void CPU::ALU(){
    switch(buffer2.AluOP)
    {
        case 1: //ADD & ADDI
            if(buffer2.AluSrc) // if AluSrc =1 => IMM
            result = buffer2.Rs_Value + buffer2.RtImm;
            else result=buffer2.Rs_Value +buffer2.Rt_Value;
            break;
        case 2: //XOR
            result = buffer2.Rs_Value ^ buffer2.Rt_Value;
            break;
        case 3: //lw OR SW
            if(buffer2.AluSrc)
            result = buffer2.Rs_Value + buffer2.RtImm;//make sure
            else cout<<"error"<<endl;
            break;
        case 4: //slt
            if(buffer2.Rs_Value<buffer2.Rt_Value) result=1;
            else result=0;
            break;
        /*case 10:
            //return hatt3emel f alu walla mem
        try{

            int returnPoint = st.pop();
            result2 = returnPoint;
        } catch (QString Error) {
            qDebug() <<Error;
        }


  /*  case 5://beq
        if(buffer2.Rs_value == buffer2.Rt_Value)
            result = PC + buffer2.RtImm;
        else result = PC;*/ //ble's execution is now implemented in ALU2
    }
}

void CPU::ALU2()
{

    if(MyCU.Branch)//BLE
        if(MyReg[buffer1.Curr_Instruction.rs]<=MyReg[buffer1.Curr_Instruction.rt])
        {
            result2 = buffer1.PC + buffer1.Curr_Instruction.imm + 1;
            buffer2.BranchTaken = true;
        }
    if(MyCU.Jump)
        switch(MyCU.ALUOp){
        case 6: //j
            result2 = buffer1.Curr_Instruction.jAddress; //pc = jaddress
            brek;
        case 7: //jal
             result2 = buffer1.Curr_Instruction.jAddress;
             MyReg[31]=buffer1.PC+1;//we return to next instruction not the current pc which is the location of jal
             break;
        case 8: //jr
            result2=MyReg[buffer1.Curr_Instruction.rs];
        case 9: //jump_procedure
            result2 = buffer1.Curr_Instruction.jAddress;
            try
            {
                st.push(buffer1.PC+1);
            } catch (QString Error) {
                qDebug()<<Error;

            }
        case 10:
            //return hatt3emel f alu walla mem
            try{

                int returnPoint = st.pop();
                result2 = returnPoint;
            } catch (QString Error) {
                qDebug() <<Error;
            }

        }

}

void CPU::Up_Memory()
{
    if (buffer3.MemtoReg)
        Mem_res = MyMem[buffer3.Res_Alu];

    if (buffer3.MemWrite)
        MyMem[buffer3.Res_Alu] = buffer3.Rt_Value;
}

void CPU::Up_Reg()
{
    if(buffer4.WBReg)
    {
        if(buffer4.MemtoReg)
            MyReg[buffer4.Reg_destination] = buffer4.Mem_Result;
        else
            MyReg[buffer4.Reg_destination] = buffer4.Alu_Result;
    }
}


void CPU::Execute()
{
    int clk = 0;
    int PC = 0;
    // CYCLE 0
    // IF
    current = MyIM[PC];
    Update_buffer1(current);
    clk++;
    Up_PC(); //what if it's only one instruction? if(pc<size) update?
    // CYCLE 1
    //ID
    MyCU.Set(buffer1.Curr_Instruction);
    Update_buffer2();
    //JUMP or BRANCH?
    ALU2();
    //IF
    current = MyIM[PC];
    Update_buffer1(current);
    clk++;
    Up_PC();
    // CYCLE 2
    // EX
    ALU();
    Update_buffer3();
    //ID
    MyCU.Set(buffer1.Curr_Instruction);
    Update_buffer2();
    ALU2();
    //IF
    current = MyIM[PC];
    Update_buffer1(current);
    clk++;
    Up_PC();
    // CYCLE 3
    // MEM
    Up_Memory();
    Update_buffer4();
    // EX
    ALU();
    Update_buffer3();
    // ID
    MyCU.Set(buffer1.Curr_Instruction);
    Update_buffer2();
    ALU2();
    // IF
    current = MyIM[PC];
    Update_buffer1(current);
    clk++;
    Up_PC();

    while(PC < MyIM.size()) {
        // WB
        Up_Reg();
        // MEM
        Up_Memory();
        Update_buffer4();
        // EX
        ALU();
        Update_buffer3();
        // ID
        MyCU.Set(buffer1.Curr_Instruction);
        Update_buffer2();
        // BRANCH or JUMP?
        ALU2();
        // IF
        current = MyIM[PC];
        Update_buffer1(current);
        clk++;
        Up_PC();
    }

    // CYCLE SIZE - 3
    Up_Reg();
    Up_Memory();
    Update_buffer4();
    ALU();
    Update_buffer3();
    MyCU.Set(buffer1.Curr_Instruction);
    Update_buffer2();
    ALU2();
    clk++;
    // CYCLE SIZE - 2
    Up_Reg();
    Up_Memory();
    Update_buffer4();
    ALU();
    Update_buffer3();
    clk++;
    // CYCLE SIZE - 1
    Up_Reg();
    Up_Memory();
    Update_buffer4();
    clk++;
    // CYCLE SIZE
    Up_Reg();
    clk++;
}



void CPU:: Forwarding()
    {
        bool StallFlag = false;
        if (buffer2.Rs == buffer3.Reg_destination )
        {
            if(buffer3.MemtoReg)      // Stall if insruction before reads from memory
            {
                StallFlag = true;
            }
            else
            {
                buffer2.Rs_Value = buffer3.Res_Alu;
            }
        if (buffer2.RtReg == buffer3.Reg_destination)
        {
            if(buffer3.MemtoReg)      // Stall if insruction before reads from memory
            {
                StallFlag = true;
            }
            else
            {
                buffer2.Rt_Value = buffer3.Res_Alu;
            }
         }
        if (buffer2.Rs == buffer4.Reg_destination)
        {
            if(buffer4.MemtoReg)
            {
                buffer2.Rs_Value = buffer4.Mem_Result;
            }
            else
            {
                buffer2.Rs_Value = buffer4.Alu_Result;
            }
        }
        if (buffer2.RtReg == buffer4.Reg_destination)
        {
            if(buffer4.MemtoReg)
            {
                buffer2.Rt_Value = buffer4.Mem_Result;
            }
            else
            {
                buffer2.Rt_Value = buffer4.Alu_Result;
            }
        }
    }
  /*if(StallFlag){

  }*/
}
