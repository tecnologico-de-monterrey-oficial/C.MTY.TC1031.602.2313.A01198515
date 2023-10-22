#include <iostream>
#include "Heap.h"
#include "MinHeap.h"

using namespace std;

int main() {
    Heap<int> maxHeap;
    MinHeap<int> minHeap;

    int choice;
    int data;

    do {
        cout << "Menú:\n";
        cout << "1. Push (Max Heap)\n";
        cout << "2. Push (Min Heap)\n";
        cout << "3. Pop (Max Heap)\n";
        cout << "4. Pop (Min Heap)\n";
        cout << "5. Top (Max Heap)\n";
        cout << "6. Top (Min Heap)\n";
        cout << "7. Is Empty (Max Heap)\n";
        cout << "8. Is Empty (Min Heap)\n";
        cout << "9. Size (Max Heap)\n";
        cout << "10. Size (Min Heap)\n";
        cout << "11. Heap Sort Ascendente (Max Heap)\n";
        cout << "12. Heap Sort Descendente (Min Heap)\n";
        cout << "0. Salir\n";
        cout << "Ingrese su elección: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Ingrese un entero: ";
                cin >> data;
                maxHeap.push(data);
                break;
            case 2:
                cout << "Ingrese un entero: ";
                cin >> data;
                minHeap.push(data);
                break;
            case 3:
                try {
                    data = maxHeap.pop();
                    cout << "Dato eliminado (Max Heap): " << data << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            case 4:
                try {
                    data = minHeap.pop();
                    cout << "Dato eliminado (Min Heap): " << data << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            case 5:
                try {
                    data = maxHeap.top();
                    cout << "Dato con mayor prioridad (Max Heap): " << data << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            case 6:
                try {
                    data = minHeap.top();
                    cout << "Dato con mayor prioridad (Min Heap): " << data << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            case 7:
                cout << "Max Heap está vacío: " << (maxHeap.isEmpty() ? "Sí" : "No") << endl;
                break;
            case 8:
                cout << "Min Heap está vacío: " << (minHeap.isEmpty() ? "Sí" : "No") << endl;
                break;
            case 9:
                cout << "Tamaño de Max Heap: " << maxHeap.getSize() << endl;
                break;
            case 10:
                cout << "Tamaño de Min Heap: " << minHeap.getSize() << endl;
                break;
            case 11:
                while (!maxHeap.isEmpty()) {
                    data = maxHeap.pop();
                    cout << data << " ";
                }
                cout << endl;
                break;
            case 12:
                while (!minHeap.isEmpty()) {
                    data = minHeap.pop();
                    cout << data << " ";
                }
                cout << endl;
                break;
            case 0:
                break;
            default:
                cout << "Opción no válida. Inténtelo de nuevo." << endl;
        }
    } while (choice != 0);

    return 0;
}
