#include <iostream>
using namespace std;
#include "LinkedList.h"

int main() {

    LinkedList<string> list;
    cout << list.findData("Cuchara") << endl;
    try {
        list.insert(2,"Vaso");
    } catch (out_of_range &e) {
        cout << e.what() << endl;
    }
    list.addLast("Cuchara");
    list.addFirst("Olla");
    list.addFirst("Estufa");
    list.addFirst("Jarra");
    list.addFirst("Plato");
    list.print();
    list.addLast("Cuchara");
    list.print();
    try {
        list.insert(2,"Vaso");
    } catch (out_of_range &e) {
        cout << e.what() << endl;
    }
    cout << "Tamaño de la lista: " << list.getSize() << endl;
    list.print();
    cout << list.findData("Cuchar") << endl;


    return 0;
}