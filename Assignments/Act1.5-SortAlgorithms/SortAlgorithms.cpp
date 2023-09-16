// Rosendo De Los Rios Moreno
// A01198515
// IRS
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// Obtiene el tiempo inicial para calcular el tiempo transcurrido por un algoritmo
void startTime(chrono::high_resolution_clock::time_point &begin)
{
  // start time
  begin = std::chrono::high_resolution_clock::now();
  
}

// Imprime el tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función
void getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) 
{
    end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed.count() * 1e-9);
}

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
}

// Crea una lista aleatoria de enteros
void createListInt(vector<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000 + 1;
    list.push_back(num);
  }
}

// Crea una lista aleatoria de caracteres
void createListChar(vector<char> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = 91;
    while (num >= 91 && num <= 96)
    {
      num = rand() % 58 + 65;
    }
    list.push_back(char(num));
  }
}

// Algoritmo de Ordenamiento por Intercambio
template<class T>
void swapSort(vector<T> &list, int &comparisons, int &swaps) {
    // Iteración de cada una de las pasadas
    for (int i=0; i<list.size()-1; i++) {
        // Iteración del primer elemento con el resto
        for (int j=i+1; j<list.size(); j++) {
            // Incrementamos en 1 el número de comparaciones
            comparisons++;
            // Comparamos el list[i] con list[j]
            if (list[i] > list[j]) {
                // Incrementamos el valor de intercambios
                swaps++;
                // Intercambiamos i con j
                swap(list, i, j);
            }
        }
    }
}

// Algoritmos de ordenamiento burbuja
template<class T>
void bubbleSort(vector<T> &list, int &comparisons, int &swaps) {
    int iter = 0;
    bool control = true;
    // Iteración por cada pasada
    while (iter < list.size()-1 && control) {
        // Inicializamos la variable de control
        control = false;
        // Comparamos en pares hasta dejar el valor mayor al final de la lista
        for (int i=1; i<list.size()-iter; i++) {
            // Incrementamos en 1 el número de comparaciones
            comparisons++;
            // Comparamos el list[i-1] con list[i]
            if (list[i-1] > list[i]) {
                // Incrementamos el valor de intercambios
                swaps++;
                // Intercambiamos i con j
                swap(list, i-1, i);
                // Si hubo intercambio cambiamos a true la variable de control
                control = true;
            }
        }
        // Incrementamos en 1 la variable iter
        iter++;
    }
}

template <class T>
void selectionSort(vector<T> &list, int &comparisons, int &swaps) {
    for (int i=0; i<list.size()-1; i++) {
        int minIndex = i;
        for (int j=i+1; j<list.size(); j++) {
            // increment5amos comparaciones
            comparisons++;
            // Comparamos para encontrar el valor más pequeño
            if (list[j]<list[minIndex]) {
                // Asignamos a minInex j, que sería el nuevo valor más pequeño
                minIndex = j;
            }
        }
        // Hacemos el intercambio
        if (minIndex != i) {
            swap(list, minIndex, i);
            // Incrementamos los intercambios
            swaps++;
        }
    }
}

template <class T>
void insertionSort(vector<T> &list, int &comparisons, int &swaps) {
    for (int i=1; i<list.size(); i++) {
        int j=i-1;
        while (j>=0) {
            // Incrementamos las comparaciones
            comparisons++;
            // comparamos los valores de j y j+1
            if (list[j+1]<list[j]) {
                // Hacemos el intercambio
                swap(list, j, j+1);
                // Incrementamos los intercambios
                swaps++;
            } else {
                j = -1; // break
            }
            // Decrementamos el valor de j
            j--;
        }
    }
}

template <class T>
void insertionSort1(vector<T> &list, int &comparisons, int &swaps) {
    for (int i=1; i<list.size(); i++) {
        int j=i-1;
        while (j>=0 && list[j+1]<list[j]) {
            // Incrementamos las comparaciones
            comparisons++;
            // Hacemos el intercambio
            swap(list, j, j+1);
            // Incrementamos los intercambios
            swaps++;
            // Decrementamos el valor de j
            j--;
        }
        if (j>=0) {
            // Incrementamos las comparaciones
            comparisons++;
        }
    }
}

template<class T>
void merge(vector<T> &list, int left, int mid, int right) {
    // Creamos lista temporal del lado izquierdo
    vector<T> listLeft;
    for (int i=left; i<=mid; i++) {
        listLeft.push_back(list[i]);
    }

    // Creamos lista temporal del lado derecho
    vector<T> listRight;
    for (int j=mid+1; j<=right; j++) {
        listRight.push_back(list[j]);
    }
    // Definimos indice auxiliar donde voy a ir ordenando lo numeros
    int auxIndex = left;
    // Comparamos las listas
    // Creamos dos índices, uno para cada lista
    int leftIndex = 0;
    int rightIndex = 0;
    while (leftIndex < listLeft.size() && rightIndex < listRight.size()) { // compara mientras hay elementos por comparar
        // Comparamos listLeft[leftIndex] con listRight[rightIndex]
        if (listLeft[leftIndex] < listRight[rightIndex]) {
            // El valor de la izquierda es menor al de la derecha
            list[auxIndex] = listLeft[leftIndex];
            // Incrementamos el valor de leftIndex
            leftIndex++;
        } else {
            // El valor de la derecha es menor al valor de la izquieda
            list[auxIndex] = listRight[rightIndex];
            // Incrementamos el valor de leftIndex
            rightIndex++;
        }
        // Incremenramos indice auxiliar
        auxIndex++;
    }
    // Se vacían los valor pendientes que ya no se pueden comparar
    // Vaciamos los valores restantes del lado izquierdo
    while (leftIndex < listLeft.size()) {
        // El valor de la izquierda es menor al de la derecha
        list[auxIndex] = listLeft[leftIndex];
        // Incrementamos el valor de leftIndex
        leftIndex++;
        // Incremenramos indice auxiliar
        auxIndex++;
    } 
    // Vaciamos los valores restantes del lado derecho
    while (rightIndex < listRight.size()) {
        // El valor de la derecha es menor al valor de la izquieda
        list[auxIndex] = listRight[rightIndex];
        // Incrementamos el valor de leftIndex
        rightIndex++;
        // Incremenramos indice auxiliar
        auxIndex++;
    }
}

template<class T>
void mergeSort(vector<T> &list, int left, int right) {
    if (left < right) { // Condición de control
        // Vamos a calcular mid
        int mid = left + (right - left) / 2;
        // Ordenamos la lista de la izquierda
        mergeSort(list, left, mid);
        // Ordenamos la lista de la derecha
        mergeSort(list, mid+1, right);
        // Merge
        merge(list, left, mid, right);
    }
}

template<class T>
int getPivot(vector<T> &list, int left, int right) {
    // Definimos el pivote
    int pivot = right;
    // Definimos un índice auxiliar
    int auxIndex = left - 1;
    // Itereamos la lista desde left hasta right - 1
    for (int index=left; index<right; index++) {
        // comparamos el valor de index con el valor del pivot
        if (list[index] < list[pivot]) {
            // Incrementamos el indice auxiliar
            auxIndex++;
            // Intercambiamos el índice auxliar con index
            swap(list, index, auxIndex);
        }
    }
    // Incrementamos el indice auxiliar
    auxIndex++;
    // Intercambiamos el índice auxliar con index
    swap(list, pivot, auxIndex);
    // Regresamos el valor del indice auxiliar
    return auxIndex;
}

template<class T>
void quickSort(vector<T> &list, int left, int right) {
    if (left < right) {
        // Obtenemos la posición final del privote
        int pivot = getPivot(list, left, right);
        // Ordenamos la lista del lado izquierdo
        quickSort(list, left, pivot-1);
        // Ordenamos la lista del lado derecho
        quickSort(list, pivot+1, right);
    }
}


int main() {

    // Semilla para generar números aleatorios
    srand(time(0));

    // Variables para calcular el tiempo de ejecución de una función
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;

    vector<int> list = {15,7,3,9,12,5,2};
    // createListInt(list, 100);
    vector<int> listAux;
    print(list);
    int comparisons = 0;
    int swaps = 0;
    listAux = list;
    startTime(begin);
    swapSort(listAux, comparisons, swaps);
    getTime(begin, end);
    cout << "Ordenamiento por Intercambio" << endl;
    print(listAux);
    cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
    listAux = list;
    comparisons= 0;
    swaps = 0;
    startTime(begin);
    bubbleSort(listAux, comparisons, swaps);
    getTime(begin, end);
    cout << "Ordenamiento por Burbuja" << endl;
    print(listAux);
    cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
    listAux = list;
    comparisons= 0;
    swaps = 0;
    startTime(begin);
    selectionSort(listAux, comparisons, swaps);
    getTime(begin, end);
    cout << "Ordenamiento por Selección" << endl;
    print(listAux);
    cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
    listAux = list;
    comparisons= 0;
    swaps = 0;
    startTime(begin);
    insertionSort1(listAux, comparisons, swaps);
    getTime(begin, end);
    cout << "Ordenamiento por Inserción" << endl;
    print(listAux);
    cout << "Comparaciones: " << comparisons << " - intercambios: " << swaps << endl;
    listAux = list;
    startTime(begin);
    mergeSort(listAux, 0, listAux.size()-1);
    getTime(begin, end);
    cout << "Ordenamiento por Merge" << endl;
    print(listAux);
    listAux = list;
    startTime(begin);
    quickSort(listAux, 0, listAux.size()-1);
    getTime(begin, end);
    cout << "Ordenamiento Rápido" << endl;
    print(listAux);
    
    return 0;
}