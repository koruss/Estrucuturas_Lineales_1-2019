#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#define DEFAULT_MAX_SIZE 1024
#include "list.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename E>

class ArrayList : public List<E>{//herencia

private:
    E *elements;
    int max;
    int size;
    int pos;

public:
    ArrayList(int maxSize = DEFAULT_MAX_SIZE) {//Constructor de la clase
        elements = new E[maxSize];
        max = maxSize;
        size = 0;
        pos = 0;
    }

    virtual ~ArrayList() {//destructor de la clase
        delete [] elements;
    }

    void insert(E element){//inserta un elemento en la posicion
        if(size == max){
            duplicate();
        }
        for(int i = size; i > pos; i--){
            elements[i] = elements[i-1];
        }
        elements[pos] = element;
        size++;
        }

        void append(E element){// Metodo append agrega un elemento al final
        if(size == max){
            duplicate();
        }
        elements[size] = element;
        size++;
    }

    E remove() throw(runtime_error){
        if(size == 0){
            throw runtime_error("Empty list.");
        }
        if((pos < 0) || (pos >= size)){
            throw runtime_error("Index out of bounds.");
        }
        E res = elements[pos];
        for(int i = pos; i < size-1; i++){
            elements[i] = elements[i+1];
        }
        size--;
        return res;
    }

    void clear(){//Elimina todos los elementos de la lista y la deja vacia
        size = 0;
        pos = 0;
        delete [] elements;
        elements = new E[max];
    }

    E getElement() throw(runtime_error){//retorna el elemento en la posicon actual
        if((pos < 0) || (pos >= size)){
            throw runtime_error("Index out of bounds.");
        }
        return elements[pos];
    }

    void goToStart(){//mueve la posicion actual al inicio de la lista
        pos = 0;
    }

    void goToEnd(){//mueve la posicion actual al final de la lista
        pos = size;
    }

    void goToPos(int newPos) throw(runtime_error){//Mueve la posición actual a la posición indicada por parametro
        if((newPos < 0) || (newPos > size)){
            throw runtime_error("Index out of bounds.");
        }
        pos = newPos;
    }

    void next(){//Mueve la posición actual al siguiente elemento, si lo hay
        if(pos < size){
            pos++;
        }
    }

    void previous(){//Mueve la posición actual al elemento anterior, si lo hay
        if(pos > 0){
            pos--;
        }
    }

    bool atStart(){//Retorna verdadero si la posición actual de la lista se encuentra al inicio. De otro modo retorna falso
        return pos == 0;
    }

    bool atEnd(){//Retorna verdadero si la posición actual de la lista se encuentra al final. De otro modo retorna falso
        return pos == size;
    }



    int getPos(){//Retorna un entero con la posición actual dentro de la lista
        return pos;
    }

    int getSize(){//Retorna el tamaño de la lista
        return size;
    }

    bool contains(E element){
        for(int c=0;c<size;c++){
            if(elements[c]==element)return true;
        }
        return false;

    }

    int indexOf(E element){
        for(int c=0;c<size;c++){
            if(elements[c]==element)return c;
        }
        return -1;



    }

    void extend(List<E> *L){
        for(L->atStart();!L->atEnd();L->next()){
            append(L->getElement());
        }
    }

    void print(){
       int num=0;
       cout<<endl;
       cout<<"Lista: ";
       while(num<size){
           cout<<elements[num]<<"-";
           num++;
       }
      cout<<endl;
      cout<<endl;

    }

    void duplicate(){
        E *temp = new E[max*2];
        for(int c=0;c<max;c++){
            temp[c]=elements[c];
        }
        this->max=max*2;
        delete [] elements;
        this->elements=temp;

    }


};
#endif // ARRAYLIST_H
