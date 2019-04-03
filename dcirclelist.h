#ifndef DCIRCLELIST_H
#define DCIRCLELIST_H

#include "dnode.h"
#include <stdexcept>
#include <cstdlib>
#include "dlinkedlist.h"

using namespace std;


template<typename E>

class DCircleList{
private:
    int size;
    DNode<E> *current;

public:
    DCircleList(){//Constructor
        size=0;
        current=NULL;

    }
    ~DCircleList(){
        clear();

    }
    void insert(E element){
        cout<<"Insertando"<<endl;
        if(size==0){
            current=new DNode<E>(element);
            current->next=current;
            current->previous=current;
            size++;
        }
        else{
            current->next=current->next->previous= new DNode<E>(element,current->next,current);
            current=current->next;
            size++;
        }
    }

    E remove()throw(runtime_error){
        if(size==0)throw runtime_error("List is Empty");
        DNode<E> *temp= current;
        E result=temp->element;
        current=temp->previous;
        current->next=temp->next;
        temp->next->previous=current;
        delete temp;
        size--;
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

                DNode<E> *temp=new DNode<E>();
                temp=current->next;
                current->next=temp->next;
                delete temp;
                size--;
            }
        }



    }

    E getFront(){
        return current->next->element;

    }

    E getBack(){
        return current->previous->element;

    }

    void next(){
        current=current->next;

    }

    void previous(){
        current=current->previous;

    }

    int getSize(){
        return size;

    }

    void print(){
        cout<<"Lista: ";
        for(int i=0;i<getSize();i++){
            cout<<current->element<<"-";
            next();
        }
        cout<<endl;
    }


    DlinkedList<E>* getElements(bool reversed=false){
        DlinkedList<E> *list=new DlinkedList<E>();
        if(reversed==false){
            for(int i=0;i<getSize();i++){
                list->append(current->element);
                next();
            }

        }
        else{

            for(int i=0;i<getSize();i++){
                previous();
                list->append(current->element);
            }
        }
        list->print();
        return list;

    }

};

#endif // DCIRCLELIST_H
