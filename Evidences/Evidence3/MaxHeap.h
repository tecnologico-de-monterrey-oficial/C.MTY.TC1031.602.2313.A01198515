#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include "LogEntry.h"
#include <vector>

class MaxHeap {
public:
    MaxHeap();
    void BuildHeap(std::vector<LogEntry>& data);
    void HeapSort(std::vector<LogEntry>& data);
    void MaxHeapSort(std::vector<LogEntry>& data); // Cambiado a pública
private:
    void MaxHeapify(std::vector<LogEntry>& data, int index, int heapSize);
};

MaxHeap::MaxHeap() {}

void MaxHeap::BuildHeap(std::vector<LogEntry>& data) {
    for (int i = data.size() / 2 - 1; i >= 0; --i) {
        MaxHeapify(data, i, data.size());
    }
}

void MaxHeap::MaxHeapify(std::vector<LogEntry>& data, int index, int heapSize) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Compara el valor del elemento en 'index' con sus hijos (left y right)
    if (left < heapSize && (data[left].ip > data[largest].ip || 
        (data[left].year > data[largest].year) || 
        (data[left].year == data[largest].year && data[left].month > data[largest].month) ||
        (data[left].year == data[largest].year && data[left].month == data[largest].month && data[left].day > data[largest].day) ||
        (data[left].year == data[largest].year && data[left].month == data[largest].month && data[left].day == data[largest].day && data[left].time > data[largest].time))) {
        largest = left;
    }

    if (right < heapSize && (data[right].ip > data[largest].ip || 
        (data[right].year > data[largest].year) || 
        (data[right].year == data[largest].year && data[right].month > data[largest].month) ||
        (data[right].year == data[largest].year && data[right].month == data[largest].month && data[right].day > data[largest].day) ||
        (data[right].year == data[largest].year && data[right].month == data[largest].month && data[right].day == data[largest].day && data[right].time > data[largest].time))) {
        largest = right;
    }

    if (largest != index) {
        std::swap(data[index], data[largest]);
        MaxHeapify(data, largest, heapSize);
    }
}

void MaxHeap::MaxHeapSort(std::vector<LogEntry>& data) {
    BuildHeap(data); // Construye el heap máximo
    for (int i = data.size() - 1; i > 0; --i) {
        std::swap(data[0], data[i]); // Intercambia el elemento máximo con el último
        MaxHeapify(data, 0, i); // Restaura la propiedad del heap máximo
    }
}

void MaxHeap::HeapSort(std::vector<LogEntry>& data) {
    MaxHeapSort(data); // Ordena utilizando el heap máximo
}

#endif // MAX_HEAP_H
