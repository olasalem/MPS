#include "controlunit.h"


ControlUnit::ControlUnit()
{
}
void ControlUnit::Reset()
{
    RegDst = false;
    Branch = false;
    MemRead = false;
    MemtoReg = false;
    MemWrite = false;
    ALUSrc = false;
    RegWrite = true;
    ALUOp = 0;
}
void ControlUnit::Set(inst Curr_Inst)
{
    Reset();   // Initially reset all
    //RegDst & ALUSrc
   if(Curr_Inst.imm==0){
       RegDst = 1;
       ALUSrc = 1;
   }
   // Branch
   if(Curr_Inst.jAddress){
       Branch = 1;
       RegWrite = 0;
   }
   //MemRead & MemReg
   if(Curr_Inst.instType == "LW" ){
       MemRead = MemtoReg = 1;
       RegWrite = 1;
   }
   //MemWrite & RegWrite
   if(Curr_Inst.instType == "SW"){
       MemWrite = 1;
       RegWrite = 0;
   }
   //ALUOp
   if(Curr_Inst.instType == "ADD" || uff1.Curr_Instruction.instType == "ADDI" ){   // 1 = Addition
       ALUOp = 1;
   }
   else if(Curr_Inst.instType == "XOR") {  // 2 = XORing
       ALUOp = 2;
   }
   else if(Curr_Inst.instType == "SW" || Curr_Inst.instType == "LW") {  // 3 = Store Word or Load Word , u execute either one by checking other signals
       ALUOp = 3;
   }
   else if(Curr_Inst.instType == "SLT") {  // 4 = SLT
       ALUOp = 4;
   }
   else if(Curr_Inst.instType == "BLE") {  // 5 = BLE
       ALUOp = 5;
   }
   else if(Curr_Inst.instType == "J") {  // 6 = Jump
       ALUOp = 6;
   }
   else if(Curr_Inst.instType == "JAL") {  // 7 = Jump and Link
       ALUOp = 7;
   }
   else if(Curr_Inst.instType == "JR") {  // 8 = JR
       ALUOp = 8;
   }
   else {
       ALUOp = 0;           // Invalid Instruction
   }
}
ControlUnit::~ControlUnit()
{
}
