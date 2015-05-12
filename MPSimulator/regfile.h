#ifndef REGFILE_H
#define REGFILE_H

#include <cstring>

class RegFile
{
    const int static regSize = 32;
    int reg[regSize];
public:
    RegFile(){
        memset(reg, 0, sizeof reg);
    }
    ~RegFile(){
        memset(reg, 0, sizeof reg);
    }
    RegFile & operator=(const RegFile & temp){ //copy constructor
        for (int i=0; i<32; i++)
            this->reg[i]=temp.reg[i];
        return *this;
    }
    int read(int num) { return reg[num];} //read a register value
    void write(int num, int value) { reg[num] = value;} //overwrite a register value

    int & operator[](unsigned int x){ //accessing a register value, L-value and R-value
        return reg[x];
    }
};

#endif // REGFILE_H
