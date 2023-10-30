#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "LogEntry.h"
#include <vector>

class MinHeap {
public:
    MinHeap();
    void BuildHeap(std::vector<LogEntry>& data);
    void HeapSort(std::vector<LogEntry>& data);
    void MinHeapSort(std::vector<LogEntry>& data); // Cambiado a pública
private:
    void MinHeapify(std::vector<LogEntry>& data, int index, int heapSize);
};

MinHeap::MinHeap() {}

void MinHeap::BuildHeap(std::vector<LogEntry>& data) {
    for (int i = data.size() / 2 - 1; i >= 0; --i) {
        MinHeapify(data, i, data.size());
    }
}

void MinHeap::MinHeapify(std::vector<LogEntry>& data, int index, int heapSize) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Compara el valor del elemento en 'index' con sus hijos (left y right)
    if (left < heapSize && (data[left].ip < data[smallest].ip || 
        (data[left].year < data[smallest].year) || 
        (data[left].year == data[smallest].year && data[left].month < data[smallest].month) ||
        (data[left].year == data[smallest].year && data[left].month == data[smallest].month && data[left].day < data[smallest].day) ||
        (data[left].year == data[smallest].year && data[left].month == data[smallest].month && data[left].day == data[smallest].day && data[left].time < data[smallest].time))) {
        smallest = left;
    }

    if (right < heapSize && (data[right].ip < data[smallest].ip || 
        (data[right].year < data[smallest].year) || 
        (data[right].year == data[smallest].year && data[right].month < data[smallest].month) ||
        (data[right].year == data[smallest].year && data[right].month == data[smallest].month && data[right].day < data[smallest].day) ||
        (data[right].year == data[smallest].year && data[right].month == data[smallest].month && data[right].day == data[smallest].day && data[right].time < data[smallest].time))) {
        smallest = right;
    }

    if (smallest != index) {
        std::swap(data[index], data[smallest]);
        MinHeapify(data, smallest, heapSize);
    }
}

void MinHeap::MinHeapSort(std::vector<LogEntry>& data) {
    BuildHeap(data); // Construye el heap mínimo
    for (int i = data.size() - 1; i > 0; --i) {
        std::swap(data[0], data[i]); // Intercambia el elemento mínimo con el último
        MinHeapify(data, 0, i); // Restaura la propiedad del heap mínimo
    }
}

void MinHeap::HeapSort(std::vector<LogEntry>& data) {
    MinHeapSort(data); // Ordena utilizando el heap mínimo
}

#endif // MIN_HEAP_H
