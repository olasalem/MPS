#ifndef INST_H
#define INST_H
#include <QString>

struct inst
{
    //Information
    QString instType;
    QString instruction; //the instruction itself

    //instrucion relevant fields
    int rs;
    int rt;
    int rd;
    int jAddress;
    int imm;

};
#endif // INST_H


