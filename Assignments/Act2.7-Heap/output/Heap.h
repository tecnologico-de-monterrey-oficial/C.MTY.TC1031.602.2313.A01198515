#ifndef Heap_h
#define Heap_h

#include <vector>

template <class T>
class Heap {
private:
    std::vector<T> heap;
    void swap(int a, int b);
    void downSort(int father);

public:
    Heap();
    Heap(std::vector<T> list);
    T pop();
    void push(T data);
    int getSize();
    void print();
    bool isEmpty();
    T top();
};

template <class T>
Heap<T>::Heap() {
}

template <class T>
void Heap<T>::swap(int a, int b) {
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

template <class T>
void Heap<T>::downSort(int father) {
    int son1;
    int son2;
    int bigBoy;

    while (father * 2 + 1 < heap.size()) {
        son1 = father * 2 + 1;

        if (father * 2 + 2 < heap.size()) {
            son2 = father * 2 + 2;
            heap[son1] > heap[son2] ? bigBoy = son1 : bigBoy = son2;
        } else {
            bigBoy = son1;
        }

        if (heap[bigBoy] > heap[father]) {
            swap(father, bigBoy);
            father = bigBoy;
        } else {
            father = heap.size();
        }
    }
}

template <class T>
Heap<T>::Heap(std::vector<T> list) {
    heap = list;
    int father = list.size() / 2 - 1;

    while (father >= 0) {
        downSort(father);
        father--;
    }
}

template <class T>
T Heap<T>::pop() {
    if (!heap.empty()) {
        T auxMax = heap[0];
        swap(0, heap.size() - 1);
        heap.pop_back();
        downSort(0);
        return auxMax;
    } else {
        throw std::out_of_range("El heap está vacío");
    }
}

template <class T>
void Heap<T>::push(T data) {
    if (!isEmpty()) {
        heap.push_back(data);
        int son = heap.size() - 1;

        while (son > 0) {
            int father = (son - 1) / 2;

            if (heap[son] > heap[father]) {
                swap(son, father);
                son = father;
            } else {
                son = 0;
            }
        }
    } else {
        heap.push_back(data);
    }
}

template <class T>
int Heap<T>::getSize() {
    return heap.size();
}

template <class T>
bool Heap<T>::isEmpty() {
    return heap.empty();
}

template <class T>
T Heap<T>::top() {
    if (!heap.empty()) {
        return heap[0];
    } else {
        throw std::out_of_range("El heap está vacío");
    }
}

#endif /* Heap_h */