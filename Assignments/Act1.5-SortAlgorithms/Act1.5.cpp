#include <iostream>
#include <vector>
using namespace std;

template<class T>
void print(vector<T> list) {
    for (auto l : list) {
        cout << l << " ";
    }
    cout << endl;
}

template<class T>
void swap(vector<T> &list, int a, int b) {
    if (list[a] != list[b]) {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
    cout << "swap" << endl;
    print(list);
}

// Algoritmo de ordenamiento por Intercambio
template <class T>
void swapSort(vector<T>& list, int &comparisons, int &swaps) {
    // Iteracion de cada una de las pasadas
    for (int i = 0; i < list.size() - 1; i++) {
        // Iteracion del primer elemento con el resto
        for (int j = i + 1; j < list.size(); j++) {
            // Incrementamos en 1 el numero de comparaciones
            comparisons++;
            // Comparamos el valor de list[i] con list[j]
            if (list[i] > list[j]) {
                // Incrementamos el valor de intercambios
                swaps++;
                // Intercambiamos i con j
                swap(list, i, j);
            }
        }
    }
}

int main() {

    vector<int> list = {12, 7, 3, 9, 12, 5, 2};
    print(list);
    
    int comparisons = 0;
    int swaps = 0;
    swapSort(list, comparisons, swaps);
    
    print(list);
    cout << "Comparaciones: " << comparisons << " - Intercambios: " << swaps << endl;

    return 0;
}
