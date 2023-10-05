#include <stdexcept>
#include <iostream>
#ifndef LinkedList_h
#define LinkedList_h
using namespace std;
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
    void insert(int index, T data);
    int findData(T data);
    T getData(int index);
    void updateAt(int index, T data);
    bool deleteAt(int index);
    bool deleteData(T data);
    T& operator[](int index);
    void operator=(LinkedList<T> list);
    void deleteList();
    void print();
    int getSize();
    bool isEmpty();
    void updateData(T oldData, T newData);
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
    // Validamos que el índice exista en la lista
    if (index >= 0 && index < size) {
        // Definimos un índex auxiliar igual a 0
        int auxIndex = 0;
        // Definimos un apuntador auxiliar igual a head
        Node<T>* aux = head;
        // Recorremos la lista
        while (auxIndex != index) {
            // Recorremos aux
            aux = aux->next;
            // Incrementamos el valor de índice auxliar
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

template<class T>
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
T LinkedList<T>::getData(int index) {
    // Validamos que index sea valido
    if (index >= 0 && index < size) {
        // Creamos un nodo auxiliar igual a head
        Node<T>* aux = head;
        // creamos un índice auxiliar igual a 0
        int auxIndex = 0;
        // Recorremos la lista mientras el índice auxiliar sea menor al índice dado
        while (auxIndex < index) {
            // Recorremos aux
            aux = aux->next;
            // Incrementar el índice auxiliar
            auxIndex++;    
        }
        // regresamos el valor de aux
        return aux->data;
    } else {
        throw out_of_range("Índice incorrecto");
    }
}

template<class T>
T& LinkedList<T>::operator[](int index) {
    // Validamos que index sea valido
    if (index >= 0 && index < size) {
        // Creamos un nodo auxiliar igual a head
        Node<T>* aux = head;
        // creamos un índice auxiliar igual a 0
        int auxIndex = 0;
        // Recorremos la lista mientras el índice auxiliar sea menor al índice dado
        while (auxIndex < index) {
            // Recorremos aux
            aux = aux->next;
            // Incrementar el índice auxiliar
            auxIndex++;    
        }
        // regresamos el valor de aux
        return aux->data;
    } else {
        throw out_of_range("Índice incorrecto");
    }
}

template<class T>
bool LinkedList<T>::deleteData(T data) {
    // Validamos si la lista esta vacía
    if (!isEmpty()) {
        // Validamos si el elemento a borrar es el primero
        if (head->data == data) {
            // Creamos un nodo auxiliar igual a head
            Node<T>* aux = head;
            // Asignamos head al siguiente elemento
            head = head->next;
            // Decremento el tamaño de la lista
            size--;
            // Libero el nodo auxiliar
            delete aux;
            // regresamos verdadero
            return true;
        } else {
            // Creamos un nodo auxiliar igual a siguiente nodo de head
            Node<T>* aux = head->next;
            // Creamos un nodo auxiliar que apunte al nodo anterior a aux;
            Node<T>* auxPrev = head;
            // Recorremos la lista hasta encontrar el dato buscado
            while (aux != nullptr) {
                // Validamos si aux->data es el elemento a borrar
                if (aux->data == data) {
                    // actualizamos el apuntador next del nodo auxiliar previo
                    auxPrev->next = aux->next;
                    // Decrementamos el tamaño de la lista
                    size--;
                    // Liberamos el nodo auxiliar
                    delete aux;
                    // regresamos verdadero
                    return true;
                }
                // Recorremos los nodos auxiliares
                auxPrev = aux;
                aux = aux->next;
            }
            // No se encontró data en la lista
            return false;
        }
    } else {
        // La lista esta vacía
        return false;
    }
}

template<class T>
bool LinkedList<T>::deleteAt(int index) {
    // Validamos si el índice es válido
    if (index >= 0 && index < size) {
        // Validamos si se quiere borrar el primer elemento
        if (index == 0) {
            // Creamos un nodo auxiliar igual a head
            Node<T>* aux = head;
            // Asignamos head al siguiente elemento
            head = head->next;
            // Decremento el tamaño de la lista
            size--;
            // Libero el nodo auxiliar
            delete aux;
            // regresamoe verdadero
            return true;
        } else {
            // Creamos un nodo auxiliar igual a siguiente nodo de head
            Node<T>* aux = head->next;
            // Creamos un nodo auxiliar que apunte al nodo anterior a aux;
            Node<T>* auxPrev = head;
            // Creamos un índice auxiliar igual =1
            int auxIndex = 1;
            // Recorremos la lista hasta encontrar el dato buscado
            while (auxIndex < index) {
                // Recorremos los nodos auxiliares
                auxPrev = aux;
                aux = aux->next;
                // incrementamos el valor de auxIndex
                auxIndex++;
            }
            // actualizamos el apuntador next del nodo auxiliar previo
            auxPrev->next = aux->next;
            // Decrementamos el tamaño de la lista
            size--;
            // Liberamos el nodo auxiliar
            delete aux;
            // regresamos verdadero
            return true;
        }
    } else {
        return false;
    }
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
bool LinkedList<T>::isEmpty() {
    return size == 0;
}

template<class T>
void LinkedList<T>::updateAt(int index, T data) {
    // Validamos si el índice es válido
    if (index >= 0 && index < size) {
        // Creamos un nodo auxiliar igual a head
        Node<T>* aux = head;
        // Creamos un índice auxiliar igual a 0
        int auxIndex = 0;
        // Recorremos la lista hasta llegar al nodo en la posición index
        while (auxIndex < index) {
            aux = aux->next;
            auxIndex++;
        }
        // Actualizamos el valor del nodo en la posición index
        aux->data = data;
    } else {
        throw out_of_range("Índice incorrecto");
    }
}

template<class T>
void LinkedList<T>::updateData(T oldData, T newData) {
    // Validamos si la lista está vacía
    if (isEmpty()) {
        throw out_of_range("La lista está vacía");
    }

    // Creamos un nodo auxiliar igual a head
    Node<T>* aux = head;

    // Recorremos la lista para buscar el elemento a actualizar
    while (aux != nullptr) {
        if (aux->data == oldData) {
            // Actualizamos el valor del nodo encontrado con newData
            aux->data = newData;
            return;  // Salimos de la función una vez actualizado
        }
        aux = aux->next;
    }

    // Si llegamos aquí, significa que no se encontró el elemento a actualizar
    throw out_of_range("El elemento a actualizar no se encuentra en la lista");
}

template<class T>
void LinkedList<T>::operator=(LinkedList<T> list) {
    // Borramos la lista actual
    deleteList();

    // Copiamos los elementos de la lista recibida
    Node<T>* listAux = list.head;
    while (listAux != nullptr) {
        addLast(listAux->data);
        listAux = listAux->next;
    }
}

template<class T>
void LinkedList<T>::deleteList() {
    // Borra todos los nodos de la lista
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

#endif
