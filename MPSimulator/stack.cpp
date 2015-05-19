#include <QString>
#include <QDebug>
#include "stack.h"
using namespace std;
Stack::Stack():topValue(-1){
}
Stack::Stack(const Stack & s){ //copy constructor
    for(int i = 0; i < maxSize; i++){
        stackPointer[i] = s.at(i);
    }

}

Stack::~Stack(){ //destructor

}
bool Stack::isEmpty() const{
    return (topValue == -1);
}
bool Stack::isFull() const{
    return (topValue == maxSize+1);
}

void Stack::push(int i){
    QString StackPushError = "Invalid Jump, Stack OverFlow";
    if(!this->isFull()){
        topValue++;
        stackPointer[topValue]= i;
    }
    else throw (StackPushError);

}
int Stack::pop(){
    QString StackPopError = "Invalid Return, The Function is not a Callee";
    if(!this->isEmpty()){
        int temp = stackPointer[topValue];
        topValue--;
        return temp;
    }
    else throw (StackPopError);


}
int Stack::top() const{
    return stackPointer[topValue];
}
int Stack::at(int i) const{
    QString StackAccessError = "Invalid Stack Access at Index: ";
    if(i >= 0 && i <= topValue)
        return stackPointer[i];
    else
        throw (StackAccessError + QString::number(i));
}
