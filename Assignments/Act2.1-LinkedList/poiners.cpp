#include <iostream>
using namespace std;
#include "Node.h"

int main() {

    /*
    int a = 5;
    int *p;
    p = new int; // new int genera un espacio en memoria de tipo entero, en p se almacena la dirección de memoria asignada
    *p = a; // A la dirección de memoria almacenada en p le asigno el valor de la variable a
    cout << "a: " << a << endl;
    cout << "p: " << p << endl;
    cout << "&a: " << &a << endl;
    cout << "&p: " << &p << endl;
    cout << "*p: " << *p << endl;
    a = *p + 2;
    cout << "a: " << a << endl;
    delete p; 
    cout << "*p: " << *p << endl;
    cout << "&p: " << &p << endl;
    a = *p + 4;
    cout << "a: " << a << endl;
    */

    Node<int> node1;
    cout << node1.next << endl;
    int a = 5;
    int b = 10;
    Node<int> node2(a);
    cout << node2.data << " " << node2.next << endl;
    Node<int> node3(b, &node2);
    cout << node3.data << " " << node3.next;
    cout << " " << node3.next->data << endl;
    return 0;
}