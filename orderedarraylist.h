#ifndef ORDEREDARRAYLIST_H
#define ORDEREDARRAYLIST_H
#include <iostream>
#include <stdexcept>
#include "arraylist.h"

using namespace std;
template <typename E>
class OrderedArrayList{
private:
    ArrayList<E> *list;

public:



    OrderedArrayList(){
        list= new ArrayList<E>();
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

    ~OrderedArrayList(){

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
        list->goToPos(pos);

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
    int indexOf(E element){//binary search
        int min=0;
        int max=getSize();
        int mitad;
        int cont=0;
        while((min<=max)&&(cont<getSize()/2)){
            bool flag;
            mitad=(min+max)/2;
            this->goToPos(mitad);
            if(element==getElement()){
                return mitad;
            }
            if(getElement()>element){
                max=mitad;
                mitad=(min+max)/2;
            }
            if(getElement()<element){
                min=mitad;
                mitad=(min+max)/2;
            }
            cont++;
        }
        return -1;
    }

    void print(){
        list->print();
    }


};


#endif // ORDEREDARRAYLIST_H
