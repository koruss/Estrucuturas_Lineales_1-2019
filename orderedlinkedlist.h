#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include "linkedlist.h"

using namespace std;
template <typename E>

class OrderedLinkedList{
private:
    LinkedList<E> *list;

public:
    OrderedLinkedList(){
        list= new LinkedList<E>();
    }

    ~OrderedLinkedList(){
    }
    void insert(E element){
        if(getSize()==0){
            list->append(element);
        }
        else{
            this->goToStart();
            while(getPos()!=getSize()){
                if(element > getElement()){
                    next();
                }

                else{
                    list->insert(element);
                    break;
                }
            }
            if(getPos()==getSize()){
                list->append(element);
            }

        }


    }

    E remove(){
        return list->remove();


    }

    void clear(){
        list->clear();

    }

    E getElement(){
        return list->getElement();

    }

    void goToStart(){
        list->goToStart();

    }

    void goToEnd(){
        list->goToEnd();

    }


    void goToPos(int pos){
        list->goToPos();

    }

    void next(){
        list->next();

    }

    void previous(){
        list->previous();

    }
    bool atEnd(){
        return list->atEnd();

    }
    bool atStart(){
        return list->atStart();

    }

    int getPos(){
        return list->getPos();

    }
    int getSize(){
        return list->getSize();

    }
    int indexOf(E element){
        goToStart();
        for(int i=0;i<getSize();i++){
            if(element==getElement()){
                return i;
            }
         next();
        }
        return -1;

    }

    void print(){
        list->print();
    }
};
#endif // ORDEREDLINKEDLIST_H
