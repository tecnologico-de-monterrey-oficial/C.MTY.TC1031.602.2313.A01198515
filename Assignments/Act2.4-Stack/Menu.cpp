#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack<int> pila; // Cambia el tipo de dato según tus necesidades

    while (true) {
        cout << "Menú:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Salir" << endl;

        int opcion;
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int elemento;
            cout << "Ingrese el elemento a agregar: ";
            cin >> elemento;
            pila.push(elemento);
            cout << "Elemento agregado correctamente." << endl;
            break;
        }
        case 2: {
            try {
                pila.pop();
                cout << "Elemento eliminado correctamente." << endl;
            }
            catch (const runtime_error& e) {
                cerr << e.what() << endl;
            }
            break;
        }
        case 3: {
            try {
                int elemento_superior = pila.top();
                cout << "Elemento superior en la pila: " << elemento_superior << endl;
            }
            catch (const runtime_error& e) {
                cerr << e.what() << endl;
            }
            break;
        }
        case 4:
            cout << "Saliendo del programa." << endl;
            return 0;
        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
        }

        // Mostrar el contenido actual de la pila
        if (!pila.isEmpty()) {
            cout << "Contenido actual de la pila: ";
            Stack<int> tempPila; // Pila temporal para mostrar los elementos sin afectar la original
            while (!pila.isEmpty()) {
                int elemento = pila.top();
                tempPila.push(elemento);
                cout << elemento << " ";
                pila.pop();
            }
            // Restaurar la pila original
            while (!tempPila.isEmpty()) {
                int elemento = tempPila.top();
                pila.push(elemento);
                tempPila.pop();
            }
            cout << endl;
        }
        else {
            cout << "La pila está vacía." << endl;
        }
    }

    return 0;
}

