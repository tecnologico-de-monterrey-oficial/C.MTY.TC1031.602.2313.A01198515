#pragma once

template <class T>
struct Node {
    T data;
    Node<T>* right;
    Node<T>* left;
    Node();
    Node(T data);
    Node(T data, Node<T>* right, Node<T>* left);
};

template<class T>
Node<T>::Node() {
    right = nullptr;
    left= nullptr;
}

template<class T>
Node<T>::Node(T data) {
    this->data = data;
    this->right = nullptr;
    this->left = nullptr;
}

template<class T>
Node<T>::Node(T data, Node<T>* right, Node<T>* left) {
    this->data = data;
    this->right = right;
    this->left= left;
}
