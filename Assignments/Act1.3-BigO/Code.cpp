#include <iostream>
#include <vector>

using namespace std;

// Escribe una función iterativa que dado un vector que contiene enteros positivos,
// regrese la suma de los enteros impares contenidos en el vector.
int funcionIterativaSumaImpares(const vector<int>& arr) {
    int suma = 0;
    for (int j = 0; j < arr.size(); ++j) {
        if (arr[j] % 2 != 0) {
            suma += arr[j];
        }
    }
    return suma;
}

// Escribe una función recursiva que dado un vector que contiene enteros positivos,
// regrese la suma de los enteros impares contenidos en el vector.
int funcionRecursivaSumaImpares(const vector<int>& arr, int idx = 0) {
    if (idx >= arr.size()) {
        return 0;
    }
    return (arr[idx] % 2 != 0) ? arr[idx] + funcionRecursivaSumaImpares(arr, idx + 1) : funcionRecursivaSumaImpares(arr, idx + 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "Suma de impares (iterativa): " << funcionIterativaSumaImpares(arr) << endl;
    cout << "Suma de impares (recursiva): " << funcionRecursivaSumaImpares(arr) << endl;

    return 0;
}
