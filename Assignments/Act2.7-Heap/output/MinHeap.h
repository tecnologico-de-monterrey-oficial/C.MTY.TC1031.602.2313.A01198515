#ifndef MinHeap_h
#define MinHeap_h

#include <vector>

template <class T>
class MinHeap {
private:
    std::vector<T> heap;
    void swap(int a, int b);
    void downSort(int father);

public:
    MinHeap();
    MinHeap(std::vector<T> list);
    T pop();
    void push(T data);
    int getSize();
    void print();
    bool isEmpty();
    T top();
};

template <class T>
MinHeap<T>::MinHeap() {
}

template <class T>
void MinHeap<T>::swap(int a, int b) {
    T aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
}

template <class T>
void MinHeap<T>::downSort(int father) {
    int son1;
    int son2;
    int littleBoy;

    while (father * 2 + 1 < heap.size()) {
        son1 = father * 2 + 1;

        if (father * 2 + 2 < heap.size()) {
            son2 = father * 2 + 2;
            heap[son1] < heap[son2] ? littleBoy = son1 : littleBoy = son2;
        } else {
            littleBoy = son1;
        }

        if (heap[littleBoy] < heap[father]) {
            swap(father, littleBoy);
            father = littleBoy;
        } else {
            father = heap.size();
        }
    }
}

template <class T>
MinHeap<T>::MinHeap(std::vector<T> list) {
    heap = list;
    int father = list.size() / 2 - 1;

    while (father >= 0) {
        downSort(father);
        father--;
    }
}

template <class T>
T MinHeap<T>::pop() {
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
void MinHeap<T>::push(T data) {
    if (!isEmpty()) {
        heap.push_back(data);
        int son = heap.size() - 1;

        while (son > 0) {
            int father = (son - 1) / 2;

            if (heap[son] < heap[father]) {
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
int MinHeap<T>::getSize() {
    return heap.size();
}

template <class T>
bool MinHeap<T>::isEmpty() {
    return heap.empty();
}

template <class T>
T MinHeap<T>::top() {
    if (!heap.empty()) {
        return heap[0];
    } else {
        throw std::out_of_range("El heap está vacío");
    }
}

#endif /* MinHeap_h */
