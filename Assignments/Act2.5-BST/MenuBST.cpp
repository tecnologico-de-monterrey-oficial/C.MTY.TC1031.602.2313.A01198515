#include <iostream>
#include "BST.h"
using namespace std;

int main() {
    BST<int> bst;
    int choice, data;
    int level; // Declara level fuera del switch

    while (true) {
        cout << "Binary Search Tree Menu" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Eliminar numero" << endl;
        cout << "3. Imprimir Arbol" <<endl;
        cout << "4. Encontrar numero dentro del arbol" <<endl;
        cout << "5. Altura" << endl;
        cout << "6. Ancestros" << endl;
        cout << "7. Que nivel estoy" << endl;
        cout << "8. Salir del programa" <<endl;
        cout << "Eleguir opicion: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Indroducir datos: ";
                cin >> data;
                bst.insert(data);
                break;
            case 2:
                cout << "Introduce dato a eliminar: ";
                cin >> data;
                if (bst.remove(data)) {
                  cout << "Dato eliminado exitosamente." << endl;
                } else {
                  cout << "Dato no encontrado en el árbol." << endl;
                }
                break;
            case 3:
                cout << "Binary Search Tree:" << endl;
                bst.print();
                break;
            case 4:
                cout << "introduccir datos a encontrar: ";
                cin >> data;
                if (bst.find(data)) {
                    cout << "Dato encontrados en el arbol." << endl;
                } else {
                    cout << "Dato no encontrado en el arbol." << endl;
                }
                break;
            case 5:
                cout << "Altura del arbol: " << bst.height() << endl;
                break;
            case 6:
                cout << "Inrtoduce un dato para enconntrar un antecesor: ";
                cin >> data;
                cout << "Aencestro de:" << data << ": ";
                bst.ancestors(data);
                break;
            case 7:
                cout << "Introduce un dato para encontrar su nivel: ";
                cin >> data;
                level = bst.whatLevelAmI(data); // Asigna el valor a level
                if (level != -1) {
                    cout << "El dato se enuentra en el nivel " << level << endl;
                } else {
                    cout << "El dato no se encuentra en el arbol" << endl;
                }
                break;
            case 8:
                cout << "Salir del programa ." << endl;
                return 0;
            default:
                cout << "Eleccion invalida, intentar nuevamente." << endl;
        }
    }

    return 0;
}

