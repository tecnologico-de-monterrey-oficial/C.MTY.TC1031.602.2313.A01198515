#pragma once
#include <iostream>

template <class T>
struct TNode {
    T data;
    TNode<T>* left;
    TNode<T>* right;
    int height;

    TNode();
    TNode(T data);
    TNode(T data, TNode<T>* left, TNode<T>* right);
};

template <class T>
class AVLTree {
private:
    TNode<T>* root;

    TNode<T>* insert(TNode<T>* node, T data);
    TNode<T>* remove(TNode<T>* node, T data);
    TNode<T>* find(TNode<T>* node, T data);
    void printTree(TNode<T>* node, std::string indent);

    int getHeight(TNode<T>* node);
    int getBalance(TNode<T>* node);
    TNode<T>* balance(TNode<T>* node);
    TNode<T>* rotateLeft(TNode<T>* z);
    TNode<T>* rotateRight(TNode<T>* y);
    TNode<T>* getMinValueNode(TNode<T>* node);

public:
    AVLTree();
    void insert(T data);
    void remove(T data);
    TNode<T>* find(T data);
    void printTree();
};

template <class T>
TNode<T>::TNode() {
    left = nullptr;
    right = nullptr;
    height = 1;
}

template <class T>
TNode<T>::TNode(T data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
    height = 1;
}

template <class T>
TNode<T>::TNode(T data, TNode<T>* left, TNode<T>* right) {
    this->data = data;
    this->left = left;
    this->right = right;
    height = 1;
}

template <class T>
AVLTree<T>::AVLTree() {
    root = nullptr;
}

template <class T>
TNode<T>* AVLTree<T>::insert(TNode<T>* node, T data) {
    if (!node) return new TNode<T>(data);

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node;  // No se permiten duplicados
    }

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    return balance(node);
}

template <class T>
TNode<T>* AVLTree<T>::remove(TNode<T>* node, T data) {
    if (!node) return node;

    if (data < node->data) {
        node->left = remove(node->left, data);
    } else if (data > node->data) {
        node->right = remove(node->right, data);
    } else {
        if (!node->left || !node->right) {
            TNode<T>* temp = node->left ? node->left : node->right;

            if (!temp) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }

            delete temp;
        } else {
            TNode<T>* temp = getMinValueNode(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }

    if (!node) return node;

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    return balance(node);
}

template <class T>
TNode<T>* AVLTree<T>::find(TNode<T>* node, T data) {
    if (!node) return nullptr;
    if (data == node->data) return node;
    if (data < node->data) return find(node->left, data);
    return find(node->right, data);
}

template <class T>
void AVLTree<T>::printTree(TNode<T>* node, std::string indent) {
    if (!node) return;
    std::cout << indent << node->data << " (" << node->height << ")" << std::endl;
    printTree(node->left, indent + "  ");
    printTree(node->right, indent + "  ");
}

template <class T>
int AVLTree<T>::getHeight(TNode<T>* node) {
    if (!node) return 0;
    return node->height;
}

template <class T>
int AVLTree<T>::getBalance(TNode<T>* node) {
    if (!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

template <class T>
TNode<T>* AVLTree<T>::balance(TNode<T>* node) {
    if (!node) return node;

    int balance = getBalance(node);

    if (balance > 1) {
        if (getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }

    if (balance < -1) {
        if (getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }

    return node;
}

template <class T>
TNode<T>* AVLTree<T>::rotateLeft(TNode<T>* z) {
    TNode<T>* y = z->right;
    TNode<T>* T2 = y->left;

    y->left = z;
    z->right = T2;

    z->height = 1 + std::max(getHeight(z->left), getHeight(z->right));
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));

    return y;
}

template <class T>
TNode<T>* AVLTree<T>::rotateRight(TNode<T>* y) {
    TNode<T>* x = y->left;
    TNode<T>* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

    return x;
}

template <class T>
TNode<T>* AVLTree<T>::getMinValueNode(TNode<T>* node) {
    TNode<T>* current = node;
    while (current->left) {
        current = current->left;
    }
    return current;
}

template <class T>
void AVLTree<T>::insert(T data) {
    root = insert(root, data);
}

template <class T>
void AVLTree<T>::remove(T data) {
    root = remove(root, data);
}

template <class T>
TNode<T>* AVLTree<T>::find(T data) {
    return find(root, data);
}

template <class T>
void AVLTree<T>::printTree() {
    printTree(root, "");
}

