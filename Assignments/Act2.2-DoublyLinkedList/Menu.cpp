#include <iostream>
#include <cstdlib>
#include <ctime>
#include "DoubleLinkedList.h" // Asegúrate de incluir tu clase DoubleLinkedList

using namespace std;

// Función para imprimir el menú
void printMenu() {
    cout << "MENU:" << endl;
    cout << "1. Agregar un elemento al principio de la lista." << endl;
    cout << "2. Agregar un elemento al final de la lista." << endl;
    cout << "3. Insertar un elemento después del índice dado." << endl;
    cout << "4. Borrar un elemento dado de la lista." << endl;
    cout << "5. Borrar un elemento en una posición de la lista." << endl;
    cout << "6. Obtener el elemento de una posición dada de la lista." << endl;
    cout << "7. Actualizar un elemento dado de la lista." << endl;
    cout << "8. Actualizar un elemento en una posición de la lista." << endl;
    cout << "9. Encontrar un elemento dado en la lista." << endl;
    cout << "10. Imprimir la lista (por cabeza)." << endl;
    cout << "11. Imprimir la lista (por cola)." << endl;
    cout << "12. Limpiar la lista." << endl;
    cout << "13. Ordenar la lista." << endl;
    cout << "14. Duplicar la lista." << endl;
    cout << "15. Eliminar elementos duplicados (Primero ordena la lista)." << endl;
    cout << "16. Salir." << endl;
    cout << "Ingrese su elección: ";
}

int main() {
    DoubleLinkedList<int> list;

    // Semilla de números aleatorios
    srand(static_cast<unsigned>(time(nullptr)));

    while (true) {
        printMenu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Ingrese el elemento a agregar al principio: ";
                cin >> data;
                list.addFirst(data);
                break;
            }
            case 2: {
                int data;
                cout << "Ingrese el elemento a agregar al final: ";
                cin >> data;
                list.addLast(data);
                break;
            }
            case 3: {
                int index, data;
                cout << "Ingrese el índice después del cual desea insertar el elemento: ";
                cin >> index;
                cout << "Ingrese el elemento a insertar: ";
                cin >> data;
                try {
                    list.insert(index, data);
                } catch (out_of_range &e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 4: {
                int data;
                cout << "Ingrese el elemento a borrar: ";
                cin >> data;
                if (list.deleteData(data)) {
                    cout << "Elemento borrado exitosamente." << endl;
                } else {
                    cout << "El elemento no se encuentra en la lista." << endl;
                }
                break;
            }
            case 5: {
                int index;
                cout << "Ingrese la posición del elemento a borrar: ";
                cin >> index;
                if (list.deleteAt(index)) {
                    cout << "Elemento en la posición " << index << " borrado exitosamente." << endl;
                } else {
                    cout << "Índice fuera de rango." << endl;
                }
                break;
            }
            case 6: {
                int index;
                cout << "Ingrese la posición del elemento que desea obtener: ";
                cin >> index;
                try {
                    int data = list[index];
                    cout << "Elemento en la posición " << index << ": " << data << endl;
                } catch (out_of_range &e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 7: {
                int index, data;
                cout << "Ingrese la posición del elemento a actualizar: ";
                cin >> index;
                cout << "Ingrese el nuevo valor: ";
                cin >> data;
                try {
                    list.updateAt(index, data);
                    cout << "Elemento actualizado exitosamente." << endl;
                } catch (out_of_range &e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 8: {
                int index, data;
                cout << "Ingrese la posición del elemento a actualizar: ";
                cin >> index;
                cout << "Ingrese el nuevo valor: ";
                cin >> data;
                try {
                    list[index] = data;
                    cout << "Elemento actualizado exitosamente." << endl;
                } catch (out_of_range &e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 9: {
                int data;
                cout << "Ingrese el elemento que desea encontrar: ";
                cin >> data;
                int index = list.findData(data);
                if (index != -1) {
                    cout << "El elemento se encuentra en la posición " << index << "." << endl;
                } else {
                    cout << "El elemento no se encuentra en la lista." << endl;
                }
                break;
            }
            case 10: {
                cout << "Elementos de la lista (por cabeza):" << endl;
                list.printHead();
                break;
            }
            case 11: {
                cout << "Elementos de la lista (por cola):" << endl;
                list.printTale();
                break;
            }
            case 12: {
                list.clear();
                cout << "La lista se ha limpiado." << endl;
                break;
            }
            case 13: {
                list.sort();
                cout << "La lista se ha ordenado." << endl;
                break;
            }
            case 14: {
                list.duplicate();
                cout << "La lista se ha duplicado." << endl;
                break;
            }
            case 15: {
                list.sort();
                list.removeDuplicates();
                cout << "Elementos duplicados eliminados." << endl;
                break;
            }
            case 16: {
                cout << "Saliendo del programa." << endl;
                return 0;
            }
            default: {
                cout << "Opción no válida. Intente nuevamente." << endl;
                break;
            }
        }
    }

    return 0;
}
