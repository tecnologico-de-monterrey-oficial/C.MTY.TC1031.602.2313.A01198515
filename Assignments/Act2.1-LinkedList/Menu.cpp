#include <iostream>
#include <cstdlib> // Para generación de números aleatorios
#include <ctime>   // Para inicializar la semilla de números aleatorios
#include "LinkedList.h"

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
    cout << "10. Imprimir la lista." << endl;
    cout << "11. Igualar la lista con otra lista (Duplicar la lista)." << endl;
    cout << "0. Salir." << endl;
    cout << "Ingrese su elección: ";
}

int main() {
    LinkedList<string> list;

    // Semilla de números aleatorios
    srand(static_cast<unsigned>(time(nullptr)));

    while (true) {
        printMenu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string data;
                cout << "Ingrese el elemento a agregar al principio: ";
                cin >> data;
                list.addFirst(data);
                break;
            }
            case 2: {
                string data;
                cout << "Ingrese el elemento a agregar al final: ";
                cin >> data;
                list.addLast(data);
                break;
            }
            case 3: {
                int index;
                string data;
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
                string data;
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
                    string data = list.getData(index);
                    cout << "Elemento en la posición " << index << ": " << data << endl;
                } catch (out_of_range &e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 7: {
                int index;
                string data;
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
                int index;
                string data;
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
                string data;
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
                cout << "Elementos de la lista:" << endl;
                list.print();
                break;
            }
            case 11: {
                LinkedList<string> duplicateList;
                duplicateList = list;
                cout << "La lista se ha duplicado exitosamente." << endl;
                break;
            }
            case 0: {
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
