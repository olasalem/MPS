#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <QString>

struct Instruction
{
    //Information
    QString instType;
    QString inst; //the instruction itself

    //instrucion relevant fields
    int rs;
    int rt;
    int rd;
    int jAddress;
    int imm;

};

#endif // INSTRUCTION_H
