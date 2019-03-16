#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include "node.h"
#include "queue.h"
#include <stdexcept>
#include <cstdlib>

using namespace std;

template<typename E>

class LinkedQueue :public Queue<E>{
private:
    Node<E> *front;
    Node<E> *back;
    int size;


public:
    LinkedQueue(){
        front=back= new Node<E>(NULL,NULL);
        size=0;


    }
    ~LinkedQueue(){
        clear();
        delete front;

    }
    void enqueue(E element){
        back=back->next=new Node<E>(element,NULL);
        size++;
    }
    E dequeue()throw(runtime_error){
        if(size==0)throw runtime_error("Queue is Empty");
        else{
        Node<E>*temp=front->next;
        E result=temp->element;
        front->next=temp->next;
        delete temp;
        size--;
        return result;
        }

    }

    void clear(){
        while(!isEmpty()){
            Node<E> * temp= front->next;
            front->next=temp->next;
            delete temp;
            size--;
        }
        back=front;
    }

    E frontValue(){
        return front->next->element;
    }

    bool isEmpty(){
        return size==0;

    }

    int getSize(){
        return size;

    }


};

#endif // LINKEDQUEUE_H
