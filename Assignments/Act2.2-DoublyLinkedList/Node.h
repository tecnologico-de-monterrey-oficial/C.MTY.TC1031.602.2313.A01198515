#pragma once

template <class T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node();
    Node(T data);
    Node(T data, Node<T>* next, Node<T>* prev);
};

template<class T>
Node<T>::Node() {
    next = nullptr;
    prev = nullptr;
}

template<class T>
Node<T>::Node(T data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

template<class T>
Node<T>::Node(T data, Node<T>* next, Node<T>* prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}
