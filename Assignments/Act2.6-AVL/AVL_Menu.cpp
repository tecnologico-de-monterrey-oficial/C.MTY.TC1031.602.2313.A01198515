#include "AVL_Tree.h"

int main() {
    AVLTree<int> avlTree;
    int choice, value;
    TNode<int>* result = nullptr;  // Declaración fuera del switch

    while (true) {
        printf("\nOpciones:\n");
        printf("1. Insertar un elemento\n");
        printf("2. Eliminar un elemento\n");
        printf("3. Buscar un elemento\n");
        printf("4. Imprimir el árbol\n");
        printf("5. Salir\n");
        printf("Ingrese la opción: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &value);
                avlTree.insert(value);
                break;
            case 2:
                printf("Ingrese el valor a eliminar: ");
                scanf("%d", &value);
                avlTree.remove(value);
                break;
            case 3:
                printf("Ingrese el valor a buscar: ");
                scanf("%d", &value);
                result = avlTree.find(value);
                if (result) {
                    printf("Elemento %d encontrado en el árbol.\n", value);
                } else {
                    printf("Elemento %d no encontrado en el árbol.\n", value);
                }
                break;
            case 4:
                printf("Árbol AVL:\n");
                avlTree.printTree();
                break;
            case 5:
                return 0;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    }

    return 0;
}
