#include <QString>
#include <QDebug>
#include "stack.h"
using namespace std;
    stack::stack(){
    }
    stack::stack(const stack & s){ //copy constructor
        for(int i=0;i<maxSize;i++){
            stackPointer[i] = s.at(i);
        }

    }

    stack::~stack(){ //destructor

    }
    bool stack::isEmpty() const{
        return (topValue==-1);
    }
    bool stack::isFull() const{
        return (topValue==maxSize+1);
    }

    void stack::push(int i){
        QString StackPushError = "Invalid Jump, Stack OverFlow";
        if(!this->isFull()){
            topValue++;
            stackPointer[topValue]= i;
        }
        else throw (StackPushError);

    }
    int stack::pop(){
        QString StackPopError = "Invalid Return, The Function is not a Callee";
        if(!this->isEmpty()){
            int temp = stackPointer[topValue];
            topValue--;
            return temp;
        }
        else throw (StackPopError);


    }
    int stack::top() const{
        return stackPointer[topValue];
    }
    int stack::at(int i) const{
        QString StackAccessError = "Invalid Stack Access at Index: ";
        if(i>=0 && i<=topValue)
            return stackPointer[i];
        else
            throw (StackAccessError + QString::number(i));
    }
