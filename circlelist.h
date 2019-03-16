#ifndef CIRCLELIST_H
#define CIRCLELIST_H


#include "node.h"
#include <stdexcept>
#include <cstdlib>

using namespace std;


template<typename E>

class CircleList{

typedef Node<E> *node;
private:
    int size=0;
    Node<E> *current;

public:

    CircleList(){
        current=NULL;
        size=0;
    }

    ~CircleList(){
        clear();
    }

    void Insert(E element){
        if(size==0){
            current= new Node<E>(element);
            current->next=current;
        }
        else{
            Node<E> *nodito=new Node<E>(element);
            current->next=nodito;
            nodito->next=current->next->next;
        }
    }

    E remove() throw(runtime_error) {
        if (size==0)throw runtime_error("No elements to remove");

        E result=current->next->element;

        if(size==1){
            delete current;
            current =NULL;
            size--;
        }
        else{
            node *temp=new Node<E>();
            temp=current->next;
            current->next=temp->next;
            delete temp;
            size--;
        }
        return result;
    }

    void clear(){
        for(int i=size; i>0; i--){
            if(size==1){
                delete current;
                current =NULL;
                size--;
            }
            else{

                Node<E> *temp=new Node<E>();
                temp=current->next;
                current->next=temp->next;
                delete temp;
                size--;
            }
        }
    }

    E getFront() throw (runtime_error){
        if (size==0)throw runtime_error("No elements");
        E result=current->next->element;
        return result;
    }

    E getBack() throw (runtime_error){
        if (size==0)throw runtime_error("No elements");
        return current->element;
    }

    void previous(){
        for(int i=0; i<size-1; i++){
            next();
        }
    }

    void next(){
        if(size>1){
            current=current->next;
        }
    }

    int getSize(){
        return size;
    }


};

#endif // CIRCLELIST_H
