
#ifndef arch_regfile_h
#define arch_regfile_h
#include <cstring>
class regfile{
public: const int static regSize = 32;
private:

    int REG[regSize];
public:

    ~regfile(){ //destructor
        memset(REG,0,sizeof REG);
    }
    regfile() { //for(int i=0; i < regSize; i++) REG[i] = 0;} //constructor, defaults the registers
        memset(REG,0,sizeof REG);
    }
    regfile & operator=(const regfile & temp){ //copy constructor
        for (int i=0; i<32; i++)
            this->REG[i]=temp.REG[i];
        return *this;
    }

    int read(int num) { return REG[num];} //read a register value
    void write(int num, int value) { REG[num] = value;} //overwrite a register value

    int & operator[](unsigned int x){ //accessing a register value, L-value and R-value
        return REG[x];
    }


};


#endif
