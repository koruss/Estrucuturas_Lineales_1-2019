#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#define DEFAULT_MAX_SIZE 1024
#include "stack.h"
#include <stdexcept>
#include <cstdlib>


using namespace std;

template<typename E>

class ArrayStack: public Stack<E>{

private:
    int max;
    int top;
    E *elements;

public:
    ArrayStack(int max=DEFAULT_MAX_SIZE)throw(runtime_error){
    if(max<1)throw runtime_error("invalid size");

    this->max=max;
    elements=new E[max];
    top=0;
        }

~ArrayStack(){
    delete [] elements;
}

void push(E element)throw(runtime_error){
    if(top==max)throw runtime_error("Stack OverFlow.");
    elements[top]=element;
    top++;
}

E pop()throw(runtime_error){
    if(top==0)throw runtime_error("Stack Underflow");
    top--;
    return elements[top];
}

E topValue()throw(runtime_error){
    if (top==0)throw runtime_error("Stack is Empty.");
    return elements[top-1];
}


void clear(){
    delete[]elements;
    elements= new E[max];
    top=0;
}

bool isEmpty(){
    return top==0;
}

int getSize(){
    return top;
}




};

#endif // ARRAYSTACK_H
