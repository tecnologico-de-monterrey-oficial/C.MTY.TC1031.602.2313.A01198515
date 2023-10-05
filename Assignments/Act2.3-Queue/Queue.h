#ifndef Queue_h
#define Queue_h
#include "Node.h"

template <class T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    Queue();
    void push(T data); // Agrega un elemento al final de la fila
    void pop(); // Elimina el primer elemento de la fila
    T front(); // Regresa el primer elemento de la fila
    bool isEmpty();
};

template <class T>
Queue<T>::Queue() {
    head = nullptr;
    tail = nullptr;
}

template <class T>
void Queue<T>::push(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

template <class T>
void Queue<T>::pop() {
    if (!isEmpty()) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
T Queue<T>::front() {
    if (!isEmpty()) {
        return head->data;
    }
    else {
        throw std::runtime_error("La cola está vacía.");
    }
}

template <class T>
bool Queue<T>::isEmpty() {
    return head == nullptr;
}

#endif
