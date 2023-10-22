#ifndef BST_h
#define BST_h

#include "TNode.h"

template <class T>
class BST {
private:
    TNode<T>* root;
    void printTree(TNode<T>* aux, int level);
    int children(TNode<T>* aux);
    int findHeight(TNode<T>* node);
    bool printAncestors(TNode<T>* node, T data);
    int findLevel(TNode<T>* node, T data, int level);

public:
    BST();
    void insert(T data);
    bool find(T data);
    bool remove(T data);
    void print();
    bool isEmpty();
    int height();
    void ancestors(T data);
    int whatLevelAmI(T data);
};


template <class T>
BST<T>::BST() {
    root = nullptr;
}

template <class T>
void BST<T>::insert(T data) {
    if (isEmpty()) {
        root = new TNode<T>(data);
    } else {
        TNode<T>* aux = root;
        while (aux != nullptr) {
            if (data < aux->data) {
                if (aux->left == nullptr) {
                    aux->left = new TNode<T>(data);
                    return;
                } else {
                    aux = aux->left;
                }
            } else {
                if (aux->right == nullptr) {
                    aux->right = new TNode<T>(data);
                    return;
                } else {
                    aux = aux->right;
                }
            }
        }
    }
}

template <class T>
bool BST<T>::find(T data) {
    TNode<T>* aux = root;
    while (aux != nullptr) {
        if (aux->data == data) {
            return true;
        } else {
            data < aux->data ? aux = aux->left : aux = aux->right;
        }
    }
    return false;
}

template <class T>
bool BST<T>::remove(T data) {
    // Implementa la eliminación aquí...
}

template<class T>
void BST<T>::printTree(TNode<T>* aux, int level) {
    if (aux != NULL) {
        printTree(aux->right,level+1);
        for (int i=0;i<level;i++) {
            std::cout << "  ";
        }
        std::cout << aux->data << std::endl;
        printTree(aux->left,level+1);
    }
}

template<class T>
void BST<T>::print() {
    if (!isEmpty()) {
        int level = 0;
        std::cout << std::endl;
        printTree(root, level);
        std::cout << std::endl;
    } else {
        std::cout << std::endl << "The BST is empty" << std::endl << std::endl;
    }
}

template <class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}

template <class T>
int BST<T>::height() {
    return findHeight(root);
}

template <class T>
int BST<T>::findHeight(TNode<T>* node) {
    if (node == nullptr) {
        return -1;
    }

    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);

    return std::max(leftHeight, rightHeight) + 1;
}

template <class T>
void BST<T>::ancestors(T data) {
    printAncestors(root, data);
    std::cout << std::endl;
}

template <class T>
bool BST<T>::printAncestors(TNode<T>* node, T data) {
    if (node == nullptr) {
        return false;
    }

    if (node->data == data) {
        return true;
    }

    if (printAncestors(node->left, data) || printAncestors(node->right, data)) {
        std::cout << node->data << " ";
        return true;
    }

    return false;
}

template <class T>
int BST<T>::whatLevelAmI(T data) {
    return findLevel(root, data, 0);
}

template <class T>
int BST<T>::findLevel(TNode<T>* node, T data, int level) {
    if (node == nullptr) {
        return -1;
    }

    if (node->data == data) {
        return level;
    }

    int leftLevel = findLevel(node->left, data, level + 1);
    int rightLevel = findLevel(node->right, data, level + 1);

    if (leftLevel != -1) {
        return leftLevel;
    }
    return rightLevel;
}

#endif /* BST_h */