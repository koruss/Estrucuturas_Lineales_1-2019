#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H


#define DEFAULT_MAX_SIZE 1024
#include "queue.h"
#include <stdexcept>
#include <cstdlib>
using namespace std;

template<typename E>



class ArrayQueue: public Queue<E>{
private:
    E *elements;
    int max,size,front,back;

public:
    ArrayQueue(int max=DEFAULT_MAX_SIZE)throw(runtime_error){
        if(max<1)throw runtime_error("Invalid size");
        this->max=max;
        this->size=0;
        this->front=0;
        this->back=0;
        elements = new E[max];//HAY QUE PENSAR EN ESTE ARRGLO COMO SI FUERA CIRCULAR ;)
    }
    ~ArrayQueue(){
        delete[]elements;
    }


    void enqueue(E element)throw(runtime_error){
        if(size==max)throw runtime_error("Queue is full");
        elements[back]=element;
        back=(back+1)%max;
        size++;
      }
    E dequeue()throw(runtime_error){
        if (size==0)throw runtime_error("Queue is Empty");
        front= (front+1)%max;
        size--;
        return elements[(front+max-1)%max];
    }


    E frontValue()throw (runtime_error){
        if(size==0)throw runtime_error("Queue is Empty");
        return elements[front];

    }

    void clear(){
        delete [] elements;
        elements= new E[max];
        size= front=back=0;
    }

    bool isEmpty(){
        return size==0;
    }

    int getSize(){
        return size;
    }


};
#endif // ARRAYQUEUE_H
