#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include <cstdlib>
#include "stack.h"
#include <stdexcept>
#include "node.h"

using namespace std;

template<typename E>

class LinkedStack: public Stack<E>{
private:
   Node<E> *top;
   int size;

public:
   LinkedStack(){
       top=NULL;
       size=0;
   }

   ~LinkedStack(){
       clear();
   }
   void push(E element){
       top=new Node<E>(element,top);
       size++;

   }

   E pop() throw(runtime_error){
       if(size==0) throw runtime_error("Stack Underflow");
       E result=top->element;
       Node<E> *temp= top;
       top=top->next;
       delete temp;
       size--;
       return result;
   }

   E topValue()throw(runtime_error){
       if(size==0)throw runtime_error("Stack is Empty");
       return top->element;
   }

   void clear(){
       while(top!=NULL){
           Node<E> *temp= top;
           top=top->next;
           delete temp;
       }
       this->size=0;
   }

   bool isEmpty(){
       return size==0;
   }

   int getSize(){
       return size;
   }


};



#endif // LINKEDSTACK_H
