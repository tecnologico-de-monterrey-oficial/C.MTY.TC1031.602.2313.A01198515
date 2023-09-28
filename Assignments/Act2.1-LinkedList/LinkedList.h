#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"

template<class T>
class LinkedList {
private:
    Node<T>* head;
    int size;
public:
    LinkedList();
    void addFirst(T data);
    void addLast(T data);
    void insert(int index, T data); // Lo voy a insertar a la derecha de index
    int findData(T data); // Busca el valor dado y regresa la posición donde se encuentra
    void print();
    int getSize();
    bool isEmpty();
};

template<class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

template<class T>
int LinkedList<T>::getSize() {
    return size;
}

template<class T>
void LinkedList<T>::addFirst(T data) {
    // Apuntamos head a un nuevo nodo que apunte a head
    head = new Node<T>(data, head);
    //Incrementamos el valor de size en 1
    size++;
}

template<class T>
void LinkedList<T>::print() {
    // Definimos un apuntador de tipo de nodo igual a head;
    Node<T>* aux = head;
    while (aux != nullptr) {
        // Imprimimos el valor del nodo
        cout << aux->data;
        if (aux->next != nullptr) {
            cout << " -> ";
        }
        // Asignamos a aux el valor de next de aux
        aux = aux->next;
    }
    // Imprimimos un salto de linea
    cout << endl;
}

template<class T>
void LinkedList<T>::addLast(T data) {
    // Validamos si la lista esta vacía
    if (isEmpty()) {
        head = new Node<T>(data);
    } else {
        // Definimos un apuntador auxiliar igual a head para recorrer la lista
        Node<T>* aux = head;
        // Vamos recorrer la lista hasta llegar al último nodo
        while (aux->next != nullptr) {
            // recorremos aux
            aux = aux->next;
        }
        // Creamos un nodo nuevo
        aux->next = new Node<T>(data);
    }
    // Incrementamos el tamaño de la lista
    size++;
}

template<class T>
void LinkedList<T>::insert(int index, T data) {
    // Validamos que el índece exista en la lista
    if (index >= 0 && index < size) {
        // Definimos un índex auxiliar igual a 0
        int auxIndex = 0;
        // DEfinimos un apuntador auxiliar igual a head
        Node<T>* aux = head;
        // Recorremos la lista
        while (auxIndex != index) {
            // Recorremos aux
            aux = aux->next;
            // Incrmenatmos el valor de índice auxliar
            auxIndex++;
        } 
        // Insertamos el valor
        aux->next = new Node<T>(data, aux->next);
        // Incrementamos el valor de size
        size++;
    } else {
        throw out_of_range("El índice no se encuentra en la lista");
    }
}

template <class T>
int LinkedList<T>::findData(T data) {
    // Definimos un apuntador auxiliar igual a head 
    Node<T>* aux = head;
    // Definimos un índice auxiliar
    int auxIndex = 0;
    // Recorremos la lista para validar si ya lo encontramos
    while (aux != nullptr) {
        // Validamos si data es el valor de aux
        if (data == aux->data) {
            // Ya lo encontramos
            return auxIndex;
        } else {
            // Recorremos aux
            aux = aux->next;
            // Incrementamos el índice auxiliar
            auxIndex++;
        }
    }
    // Al salir del while asumimos que no lo encontramos
    return -1;
    
}

template<class T>
bool LinkedList<T>::isEmpty() {
    return size == 0;
}


#endif