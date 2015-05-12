
#ifndef arch_DataMem_h
#define arch_DataMem_h
#include <cstring>
class DataMem{
public:
    const int static memSize = 1024;
private:

    int DM[memSize];
public:

    ~DataMem(){ //destructor
        memset(DM,0,sizeof DM);

    }
    DataMem() { //for(int i=0; i < memSize; i++) DM[i] = 0;}
        memset(DM,0,sizeof DM);

    }

    DataMem & operator=(const DataMem & temp){
        for (int i=0; i<memSize; i++)
            this->DM[i]=temp.DM[i];
        return *this;
    }
    int read(int num) { return DM[num];}
    void write(int address, int WriteData) { DM[address] = WriteData;}

    int & operator[](unsigned int num){
        return DM[num];
    }

};


#endif
