#ifndef BST_h
#define BST_h

#include "TNode.h"

template <class T>
class BST {
private:
    TNode<T>* root;
    void printTree(NodeT<T>* aux, int level);
public:
    BST();
    void insert(T data);
    void print();
    bool isEmpty();
};

template <class T>
BST<T>::BST() {
    root = nullptr;
}

template <class T>
void BST<T>::insert(T data) {
    // Validamos si el arbol esta vacío
    if (isEmpty())
        // El árbol está vacío
        // root va a ser igual a un nuevo nodo con el valor de data
    // Else
        // El arbol no está vacío
        // Creamos un apuntador auxiliar apuntado a roor
        // Iteramos el árbol hasta poder insertar el valor nuevo (aux != nullptr)
            // Comparamos si data es menor a aux->data
                // si es menor
                // Validamos si el apuntador del lado izquierdo de aux es nulo
                    // si es nulo
                    // aux->left va a ser igual a nuevo nodo con el valor de data
                    // nos salimos de la función
                // else
                    // no es nulo
                    // Recorremos aux hacia aux->left
            // else
                // es mayor o igual
                // Validamos si el apuntador del lado derecho de aux es nulo
                    // si es nulo
                    // aux->right va a ser igual a nuevo nodo con el valor de data
                    // nos salimos de la función
                // else
                    // no es nulo
                    // Recorremos aux hacia aux->right
        // terminamos while
    // Terminamos el if
}

template<class T>
void BST<T>::printTree(NodeT<T>* aux, int level) {
    if (aux != NULL) {
        printTree(aux->right,level+1);
        for (int i=0;i<level;i++) {
            cout << "  ";
        }
        cout << aux->data << endl;
        printTree(aux->left,level+1);
    }
}

template<class T>
void BST<T>::print() {
    if (!isEmpty()) {
        int level = 0;
        cout << endl;
        printTree(root, level);
        cout << endl;
    } else {
        cout << endl << "The BST is empty" << endl << endl;
    }
} 

template <class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}






#endif /* BST_h */