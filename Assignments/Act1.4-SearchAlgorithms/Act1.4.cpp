#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
using namespace std;

int sequentialSearch(vector<int> list, int data) {
    for (int i = 0; i < list.size(); ++i) {
        if (list[i] == data) {
            return i; // Se encontró el valor en la posición i
        }
    }
    return -1; // No se encontró el valor en la lista
}

int binarySearch(vector<int> list, int data) {
    int low = 0;
    int high = list.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (data == list[mid]) {
            return mid;
        } else {
            if (data < list[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1;
}

void startTime(chrono::high_resolution_clock::time_point &begin) {
    begin = chrono::high_resolution_clock::now();
}

void getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) {
    end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);

    cout << "Tiempo de ejecución: " << elapsed.count() * 1e-9 << " seconds." << endl;
}

void createListInt(vector<int> &list, int quantity) {
    for (int i = 0; i < quantity; i++) {
        int num = rand() % 1000000 + 1;
        list.push_back(num);
    }
}

int main() {
    srand(time(0));

    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;

    vector<int> list;
    createListInt(list, 1000); // Crear una lista de 1000 elementos

    int n = 42;

    // Búsqueda secuencial
    startTime(begin);
    int seqIndex = sequentialSearch(list, n);
    getTime(begin, end);

    if (seqIndex >= 0) {
        cout << "Búsqueda secuencial: El valor " << n << " se encuentra en la posición " << seqIndex << endl;
    } else {
        cout << "Búsqueda secuencial: El valor " << n << " no se encuentra en la lista" << endl;
    }

    // Búsqueda binaria
    startTime(begin);
    int binIndex = binarySearch(list, n);
    getTime(begin, end);

    if (binIndex >= 0) {
        cout << "Búsqueda binaria: El valor " << n << " se encuentra en la posición " << binIndex << endl;
    } else {
        cout << "Búsqueda binaria: El valor " << n << " no se encuentra en la lista" << endl;
    }

    return 0;
}
