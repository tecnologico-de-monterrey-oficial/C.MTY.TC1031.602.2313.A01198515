#include <iostream>
using namespace std;


// Suma iterativa
int sumIterative(int n) {
    int sum = 0;
    for (int i=1; i<=n; i++) {
        sum = sum + i;
    }
    return sum;
}

// Suma recursiva
int sumRecursion(int n) {
    // Condición de control
    if (n > 1) {
        return n + sumRecursion(n-1);
    } else {
        return 1;
    }
}

// Suma directa con fórmula
int sumFormula(int n) {
    return n * (n+1)/2;
}

// Suma Fibonacci Iterativa
int fibonacciIterative(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        int f1 = 1;
        int f2 = 1;
        for (int i=3; i<=n; i++) {
            int aux = f2;
            f2 = f1 + f2;
            f1 = aux;
        }
        return f2;
    }

}

// Suma Fibonacci Recursiva
int fibonacciRecursive(int n) {
    if (n == 1 || n== 2) {
        return 1;
    } else {
        return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
    }
}

// Suma bacterias Iterativa
int bacteriasIterative(int days) {
    int bacterias = 1;
    float rate = 1.44;
    for (int i=1; i<=days; i++) {
        bacterias = bacterias + bacterias * rate;
    }
    return bacterias;
}

// Suma bacterias Recursiva
int bacteriasRecursive(int days) {
    if (days>0) {
        int bacterias = bacteriasRecursive(days-1);
        float born = bacterias*1.44;
        return bacterias + born;
    } else {
        return 1;
    }
}

// Cálculo saldo de inversión Iterativa
float investmentIterative(float balance, int months) {
    float interestRate = 18.75;
    float newBalance = balance; 
    for (int i = 1; i <= months; i++) {
        newBalance = newBalance * (1 + interestRate / 100);
    }
    return newBalance;
}

// Cálculo saldo de inversión Recursiva
float investmentRecursive(float balance, int months) {
    if (months > 0) {
        return investmentRecursive(balance, months -1) * (1 + 18.75/100);
    } else {
        return balance;
    }
}

// Cálculo de potencia Iterativa
int powIterative(int n, int y) {
    int result = 1;
    for (int i = 0; i < y; i++) {
        result *= n;
    }
    return result;
}

// Cálculo de potencia Recursiva
int powRecursive(int n, int y) {
    if (y == 0) {
        return 1;
    } else {
        return n * powRecursive(n, y - 1);
    }
}

int main() {
    // Suma iterativa
    int sum1 = sumIterative(5);
    cout << "La suma de 1 al 5 es: " << sum1 << endl;
    // Suma Recursiva
    int sum2 = sumRecursion(5);
    cout << "La suma de 1 al 5 es: " << sum2 << endl;
    // Suma con Fórmula
    int sum3 = sumFormula(5);
    cout << "La suma de 1 al 5 es: " << sum3 << endl;
    // Fibonacci Iterativo
    cout << "El número fibonacci de 10 es: " << fibonacciIterative(10) << endl;
    // Fibonacci Recursivo
    cout << "El número fibonacci de 10 es: " << fibonacciRecursive(10) << endl;
    // Bacterias iterativo
    cout << "El núnero de bacterias en 10 días es: " << bacteriasIterative(10) << endl;
    // Bacterias recursivo
    cout << "El núnero de bacterias en 10 días es: " << bacteriasRecursive(10) << endl;
    // Potencia Iterativa
    cout << "El saldo final de un saldo inicial de 1000 en un lapso de 12 meses es de "<<investmentIterative(1000, 12)<< endl;
    // Potencia Recursiva
    cout << "El saldo final de un saldo inicial de 1000 en un lapso de 12 meses es de "<<investmentRecursive(1000, 12)<< endl;
    // Potencia Iterativa
    cout << "3 elevado a la 5 es: " << powIterative(3, 5) << endl;
    // Potencia Recursiva
    cout << "3 elevado a la 5 es: " << powRecursive(3, 5) << endl;
    


    return 0;
}