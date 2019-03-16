#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#define DEFAULT_MAX_SIZE 1024
#include "list.h"
#include "node.h"
#include <stdexcept>


using namespace std;

template <typename E>
class LinkedList : public List <E>
{
private:
    Node <E> *head;
    Node<E>* tail;
    Node<E>* current;
    int size;
public:
    LinkedList()
    {
        head=tail=current=new Node<E>();
        size=0;
    }
    ~LinkedList()
    {
        clear();
        delete head;
    }

    void insert(E element) //Inserta un elemento nuevo en la posición actual.
    {
        current->next=new Node<E>(element, current->next);
        if(current==tail)
        {
            tail=tail->next;
        }
        size++;
    }

    void append(E element) //Agrega un elemento nuevo en la última posición de la lista
    {
        tail->next=new Node<E>(element);
        tail=tail->next;
        size++;
    }

    E remove() throw(runtime_error) //Elimina el elemento encontrado en la posición actual. Retorna como resultado el valor
    {
        if(current->next==NULL)
        {
            throw runtime_error("No element to remove.");
        }
        E result=current->next->element;
        Node<E> *temp=current->next;
        current->next=current->next->next;
        if(current->next==NULL)
        {
            tail=current;
        }
        delete temp;
        size--;
        return result;
    }

    void clear() //Elimina todos los elementos de la lista y la deja vacía
    {
        current = head->next;
        while(head->next!=NULL)
        {
            head->next=current->next;
            delete current;
            current =head->next;
        }
        size=0;
        tail=current=head;
    }

    E getElement()throw(runtime_error) //Retorna el valor del elemento encontrado en la posición actual.
    {
        if(size==0)
            throw runtime_error("list is empty");
        if(current==tail)
            throw runtime_error("No current element");
        return current->next->element;
    }

    void goToStart() //Mueve la posición actual al inicio de la lista
    {
        current=head;
    }


    void goToEnd() //Mueve la posición actual al final de la lista
    {
        current=tail;
    }

    void goToPos(int pos)throw(runtime_error) //Mueve la posición actual a la posición indicada por parámetro
    {
        if(0>pos||pos>size)
            throw runtime_error("Index out of Bounds");
        current=head;
        for(int i=0; i<pos; i++)
        {
            current=current->next;
        }
    }

    void next() //Mueve la posición actual al siguiente elemento, si lo hay
    {
        if(current!=tail)
            current=current->next;
    }

    void previous() //Mueve la posición actual al elemento anterior, si lo hay
    {
        if(current!=head)
        {
            Node<E> *temp=head;
            while (temp->next!=current)
            {
                temp=temp->next;
            }
            current=temp;
        }
    }




    bool atStart() //Retorna verdadero si la posición actual de la lista se encuentra al inicio
    {
        return current==head;
    }

    bool atEnd() //Retorna verdadero si la posición actual de la lista se encuentra al final
    {
        return current==tail;
    }

    int getPos() //Retorna un entero con la posición actual dentro de la lista
    {
        int pos=0;
        Node<E> *temp= head;
        while(temp!=current)
        {
            pos++;
            temp=temp->next;
        }
        return pos;
    }

    int getSize() //Retorna el tamaño de la lista
    {
        return size;

    }

    void reverse() //Invierte el orden de los elementos de la lista
    {
        Node<E> *temp=this->current;
        E lista[size];
        int num=0;
        goToStart();
        for(int i=0;i<size;i++){
            lista[i]=getElement();
            next();
        }
        goToStart();
        for(int i=size-1;i>=0;i--){
            current->next->element=lista[i];
            next();
        }

}
    bool equals(List<E> *L)
    {
    }


    void print(){
        this->goToStart();
        for(int i=1;i<=size;i++){
            cout<<getElement()<<"-";
            next();
        }
        cout<<endl;
    }
};

#endif // LINKEDLIST_H
