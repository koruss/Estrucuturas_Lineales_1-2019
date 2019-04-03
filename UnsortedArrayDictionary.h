#ifndef UNSORTEDARRAYDICTIONARY_H
#define UNSORTEDARRAYDICTIONARY_H
#include "arraylist.h"
#include "dlinkedlist.h"
#include "dictionary.h"
#include "kvpair.h"
#include <stdexcept>

using namespace std;

template <typename K,typename V>

class UnsortedArrayDictionary:public Dictionary<K,V>{

   private:
    ArrayList<KVPair<K,V> > pairs;
    void notExists(K key)throw (runtime_error){
        if(contains(key))throw runtime_error("Duplicate key");

    }

    void exists(K key)throw(runtime_error){
        if(!contains(key))throw runtime_error("Key not Found");

    }

public:
    UnsortedArrayDictionary(int max=DEFAULT_MAX_SIZE):pairs(max){

    }
    ~UnsortedArrayDictionary(){}


    bool contains(K key){
        KVPair<K,V> p(key);
        for(pairs.goToStart();!pairs.atEnd();pairs.next()){
            return p==pairs.getElement();
        }
        return false;
    }

    void insert(K key,V value)throw(runtime_error){
        notExists(key);
        KVPair<K,V> p(key,value);
        pairs.append(p);

    }



    V remove(K key)throw(runtime_error){
        exists(key);
        KVPair<K,V> p=pairs.remove();
        return p.getValue();
    }

    V getValue(K key) throw(runtime_error){
        exists(key);
        KVPair<K,V> p= pairs.getElement();
        return p.getValue();
    }

    void setValue(K key,V value)throw(runtime_error){
        exists(key);
        pairs.remove();
        KVPair<K,V> p(key,value);
        pairs.append(p);

    }

    List<K>* getKeys(){
        List<K> *keys = new DlinkedList<K>();
        for(pairs.goToStart();!pairs.atEnd();pairs.next()){
            KVPair<K,V> p= pairs.getElement();
            keys->append(p.getKey());
        }
       return keys;
    }


    List<K>* getValues(){
        List<K> *values = new DlinkedList<K>();
        for(pairs.goToStart();!pairs.atEnd();pairs.next()){
            KVPair<K,V> p= pairs.getElement();
            values->append(p.getKey());
        }
       return values;
    }


    int getSize(){
        return pairs.getSize();
    }



  //IZI pizi

};
#endif // UNSORTEDARRAYDICTIONARY_H
