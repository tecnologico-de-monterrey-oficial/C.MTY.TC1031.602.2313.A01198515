#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h
#include <iostream>
using namespace std; 
#include "Node.h"

template<class T>
class DoubleLinkedList{
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;
    public:
        DoubleLinkedList();
        bool isEmpty();
        bool isHead(int index);

        void addFirst(T data);
        void addLast(T data);
        void insert(int index, T data);

        bool deleteData(T data);
        bool deleteAt(int position);

        int findData(T data);
        void getData(int position);
        void updateData(T dataFind, T dataNew);
        void updateAt(int position, T dataNew);

        T& operator[](int position);
        void operator=(DoubleLinkedList<T>& l2);

        void printHead();
        void printTale();
        int getSize();

        void clear();
        void swap(T dataB, T dataS);
        void sort();
        void duplicate();
        void removeDuplicates();


};

template<class T>
DoubleLinkedList<T>::DoubleLinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<class T>
bool DoubleLinkedList<T>::isEmpty(){
    return size == 0;
}

template<class T>
bool DoubleLinkedList<T>::isHead(int index){
    if(index < (size/2)-1){
        return true;
    }else{
        return false;
    }
}

template<class T>
void DoubleLinkedList<T>::addFirst(T data){
    if(isEmpty()){
        head = new Node<T>(data);
        tail = head;
    }else{
        head = new Node<T>(data, head, nullptr);
        head->next->prev = head;
    }
    size++;
}

template<class T>
void DoubleLinkedList<T>::addLast(T data){
    if(isEmpty()){
        tail = new Node<T>(data);
        head = tail;
    }else{
        tail = new Node<T>(data, nullptr, tail);
        tail->prev->next = tail;
    }
    size++;
}


template<class T>
void DoubleLinkedList<T>::insert(int index, T data){
    if(index == size-1){
        addLast(data);
    }else if(index < size && index >= 0){
        Node<T>* aux;
        int auxIndex;
        if(isHead(index)){
            aux = head;
            auxIndex = 0;
            while(auxIndex != index){
                aux = aux->next;
                auxIndex++;
            }
        }else{
            aux = tail;
            auxIndex = size-1;
            while(auxIndex != index){
                aux = aux->prev;
                auxIndex--;
            }
        }
        aux->next = new Node<T>(data, aux->next, aux);
        aux->next->next->prev = aux->next;
        size++;
    }else{
        cout << "Index out of range" << endl;
    }
}


template<class T>
int DoubleLinkedList<T>::findData(T data){
    Node<T>* aux = head;
    int auxIndex = 0;
    while (aux!=nullptr){
        if(aux->data == data){
            return auxIndex;
        }
        aux = aux->next;
        auxIndex++;
    }
    return -1;
}

template<class T>
void DoubleLinkedList<T>::getData(int position){
    Node<T>* aux;
    int auxIndex;
    if(position < size && position >= 0){
        if(isHead(position)){
            aux = head;
            auxIndex = 0;
            while(auxIndex != position){
                aux = aux->next;
                auxIndex++;
            }
            cout << aux->data << endl;
        }else{
            aux = tail;
            auxIndex = size-1;
            while(auxIndex != position){
                aux = aux->prev;
                auxIndex--;
            }
            cout << aux->data << endl;
        }
    }else{
        throw out_of_range("Index out of range");
    }
}

template<class T>
void DoubleLinkedList<T>::updateData(T dataFind, T dataNew){
    int index = findData(dataFind);
    if(index >= 0){
        Node<T>* aux;
        int auxIndex;
        if(isHead(index)){
            aux = head;
            auxIndex = 0;
            while(auxIndex != index){
                aux = aux->next;
                auxIndex++;
            }
        }else{
            aux = tail;
            auxIndex = size-1;
            while(auxIndex != index){
                aux = aux->prev;
                auxIndex--;
            }
        }
        aux->data = dataNew;
    }else{
        throw out_of_range("Element not found");
    }
}

template<class T>
void DoubleLinkedList<T>::updateAt(int position, T dataNew){
    if(position >= 0){
        Node<T>* aux;
        int auxIndex;
        if(isHead(position)){
            aux = head;
            auxIndex = 0;
            while(auxIndex != position){
                aux = aux->next;
                auxIndex++;
            }
        }else{
            aux = tail;
            auxIndex = size-1;
            while(auxIndex != position){
                aux = aux->prev;
                auxIndex--;
            }
        }
        aux->data = dataNew;
    }else{
        throw out_of_range("Position out of range");
    }
}


template<class T>
bool DoubleLinkedList<T>::deleteAt(int position){

    if(position == 0){
        Node<T>* aux = head;
        head = head->next;
        head->prev = nullptr;
        delete aux;
        size--;
        cout << "Element deleted at position " << position << endl;
        return true;
    }else if(position == size-1){ 
        Node<T>* aux = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete aux;
        size--;
        cout << "Element deleted at position " << position << endl;
        return true;
    }else if(position < size){ 
        Node<T>* aux;
        int auxIndex;
        if(isHead(position)){
            aux = head;
            auxIndex = 0;
            while(auxIndex != position){
                aux = aux->next;
                auxIndex++;
            }
        }else{
            aux = tail;
            auxIndex = size-1;
            while(auxIndex != position){
                aux = aux->prev;
                auxIndex--;
            }
        }
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
        delete aux;
        size--;
        cout << "Element deleted at position " << position << endl;
        return true;
    }else{
        cout << "Position out of range" << endl;
        return false;
    }
}

template<class T>
bool DoubleLinkedList<T>::deleteData(T data){
    int position = findData(data);
    if(position == 0){ 
        Node<T>* aux = head;
        head = head->next;
        head->prev = nullptr;
        delete aux;
        size--;
        cout << "Element " << data << " deleated" << endl;
        return true;
    }else if(position == size-1){ 
        Node<T>* aux = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete aux;
        size--;
        cout << "Element " << data << " deleated" << endl;
        return true;
    }else if(position < size){
        Node<T>* aux;
        int auxIndex;
        if(isHead(position)){
            aux = head;
            auxIndex = 0;
            while(auxIndex != position){
                aux = aux->next;
                auxIndex++;
            }
        }else{
            aux = tail;
            auxIndex = size-1;
            while(auxIndex != position){
                aux = aux->prev;
                auxIndex--;
            }
        }
       
        aux->prev->next = aux->next;
        
        aux->next->prev = aux->prev;
        delete aux;
        size--;
        cout << "Element " << data << " deleted" << endl;
        return true;
    }else{
        cout << "Element not found" << endl;
        return false;
    }
}



template<class T>
T& DoubleLinkedList<T>::operator[](int position){
    Node<T>* aux;
    int auxIndex;
    if(position<size){
        if(isHead(position)){
            aux = head;
            auxIndex = 0;
            while(auxIndex != position){
                aux = aux->next;
                auxIndex++;
            }
        }else{
            aux = tail;
            auxIndex = size-1;
            while(auxIndex != position){
                aux = aux->prev;
                auxIndex--;
            }
        }
        return aux->data;
    }else{
        throw out_of_range("Index out of range");
    }
}

template<class T>
void DoubleLinkedList<T>::operator=(DoubleLinkedList<T>& originalList){
    Node<T>* aux = originalList.head;
    for(int auxIndex = 0; auxIndex < originalList.size; auxIndex++){
        addLast(aux->data);
        aux = aux->next;
    }
}

template<class T>
void DoubleLinkedList<T>::printHead(){
    cout << "By head: ";
    Node<T>* aux = head;
    while(aux != nullptr){
        cout << aux->data;
        if(aux->next != nullptr){
            cout << " -> ";
        }
        aux=aux->next;
    }
    cout << endl;
}

template<class T>
void DoubleLinkedList<T>::printTale(){
    cout << "By tail: ";
    Node<T>* aux = tail;
    while(aux != nullptr){
        cout << aux->data;
        if(aux->prev != nullptr){
            cout << " <- ";
        }
        aux = aux->prev;
    }
    cout << endl;
}

template<class T>
int DoubleLinkedList<T>::getSize(){
    return size;
}

template<class T>
void DoubleLinkedList<T>::clear(){
    Node<T>* aux = head;
    while(aux != nullptr){
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete aux;
        aux = head;
        size--;
    }
    tail = nullptr;
}

template<class T>
void DoubleLinkedList<T>::swap(T dataB, T dataS){
    T aux = dataS;
    updateData(dataS, dataB);
    updateData(dataB, aux);
}

template<class T>
void DoubleLinkedList<T>::sort(){
    bool swapped = true;
    while(swapped){
        swapped = false;
        Node<T>* aux = head;
        while(aux->next != nullptr){
            if(aux->data > aux->next->data){
                swap(aux->data, aux->next->data);
                swapped = true;
            }
            aux = aux->next;
        }
    }
}

template<class T>
void DoubleLinkedList<T>::duplicate(){
    Node<T>* aux = head;
    int auxIndex = 0;
    while(aux != nullptr){
        insert(auxIndex, aux->data);
        aux = aux->next->next;
        auxIndex+=2;
    }
}

template<class T>
void DoubleLinkedList<T>::removeDuplicates(){
    for(int i = 0; i<size; i++){
        deleteAt(i);
    }
}

#endif