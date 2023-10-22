#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    Queue<int> fila; // Cambia el tipo de dato según tus necesidades

    while (true) {
        cout << "Menú:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Front" << endl;
        cout << "4. Salir" << endl;

        int opcion;
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int elemento;
            cout << "Ingrese el elemento a agregar: ";
            cin >> elemento;
            fila.push(elemento);
            cout << "Elemento agregado correctamente." << endl;
            break;
        }
        case 2: {
            try {
                fila.pop();
                cout << "Elemento borrado correctamente." << endl;
            }
            catch (const runtime_error& e) {
                cerr << e.what() << endl;
            }
            break;
        }
        case 3: {
            try {
                int primer_elemento = fila.front();
                cout << "Primer elemento en la fila: " << primer_elemento << endl;
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

        // Mostrar el contenido actual de la cola
        if (!fila.isEmpty()) {
            cout << "Contenido actual de la cola: ";
            Queue<int> tempFila; // Cola temporal para mostrar los elementos sin afectar la original
            while (!fila.isEmpty()) {
                int elemento = fila.front();
                tempFila.push(elemento);
                cout << elemento << " ";
                fila.pop();
            }
            // Restaurar la cola original
            while (!tempFila.isEmpty()) {
                int elemento = tempFila.front();
                fila.push(elemento);
                tempFila.pop();
            }
            cout << endl;
        }
        else {
            cout << "La cola está vacía." << endl;
        }
    }

    return 0;
}
