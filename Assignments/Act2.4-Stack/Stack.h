#ifndef Stack_h
#define Stack_h

#include "Node.h"

template <class T>
class Stack {
private:
    Node<T>* head;

public:
    Stack();
    void push(T data); // Agrega un elemento arriba de la pila
    void pop(); // Elimina el elemento de arriba de la pila (saco una papa)
    T top(); // regresa el valor de elemento de arriba de la pila
    bool isEmpty(); // regresa si la pila está vacía
};

template <class T>
Stack<T>::Stack() {
    head = nullptr;
}

template <class T>
void Stack<T>::push(T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
}

template <class T>
void Stack<T>::pop() {
    if (!isEmpty()) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
T Stack<T>::top() {
    if (!isEmpty()) {
        return head->data;
    }
    else {
        throw std::runtime_error("La pila está vacía.");
    }
}

template <class T>
bool Stack<T>::isEmpty() {
    return head == nullptr;
}

#endif
