#ifndef STACK_H
#define STACK_H

class Stack
{
public:
        Stack();
        Stack(const stack &);
        ~Stack();
        bool isEmpty() const;
        bool isFull() const;
        void push(int );
        int pop();
        int top() const;
        int at(int ) const;
    private:
        const int static maxSize = 4;
        int stackPointer[maxSize], topValue=-1;
};

#endif // STACK_H
