#include <iostream>
#include "dcirclelist.h"
#include "dlinkedlist.h"
#include "time.h"

using namespace std;

int main()
{
    DCircleList<int> *list= new DCircleList<int>();
    cout<<"hola"<<endl;
    for(int i=0;i<10;i++){
        list->insert(rand()%100);

    }
    list->print();


   DlinkedList<int> *listita= new DlinkedList<int>();
   listita=list->getElements(true);

}
