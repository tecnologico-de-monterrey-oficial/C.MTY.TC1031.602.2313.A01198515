#ifndef HashTable_h
#define HashTable_h

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class HashTable {
private:
    vector<string> table;
    vector<bool> status;

    size_t hash(const string& data);
    void loadMatriculasFromFile(const string& filename);

public:
    HashTable();
    void insert(const string& data);
    void remove(const string& data);
    int findData(const string& data);
    void print();
    void displayMenu();
};

HashTable::HashTable() {
    table.resize(50);  // Modificar el tamaño a 50
    status.resize(50, false);
    loadMatriculasFromFile("Matriculas.txt");
}

void HashTable::loadMatriculasFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string matricula;
        while (getline(file, matricula)) {
            insert(matricula);
        }
        file.close();
    } else {
        cerr << "Error al abrir el archivo " << filename << endl;
    }
}

size_t HashTable::hash(const string& data) {
    // Implementación simple de la función de hash para cadenas
    size_t hashValue = 0;
    for (char ch : data) {
        hashValue = hashValue * 31 + ch;
    }
    return hashValue % table.size();
}

int HashTable::findData(const string& data) {
    size_t index = hash(data);

    if (table[index] == data && !status[index]) {
        return index;
    } else {
        size_t newIndex = (index + 1) % table.size();
        while (newIndex != index && (!table[newIndex].empty() || status[newIndex])) {
            if (table[newIndex] == data && !status[newIndex]) {
                return newIndex;
            }
            newIndex = (newIndex + 1) % table.size();
        }
        return -1;
    }
}

void HashTable::insert(const string& data) {
    size_t index = hash(data);

    if (findData(data) == -1) {
        if (table[index].empty()) {
            table[index] = data;
            status[index] = false;
        } else {
            size_t newIndex = (index + 1) % table.size();
            while (newIndex != index && !table[newIndex].empty()) {
                newIndex = (newIndex + 1) % table.size();
            }
            if (newIndex != index) {
                table[newIndex] = data;
                status[newIndex] = false;
            } else {
                throw invalid_argument("La tabla está llena");
            }
        }
    } else {
        cout << "La matrícula ya existe." << endl;
    }
}

void HashTable::remove(const string& data) {
    int index = findData(data);

    if (index != -1) {
        table[index] = "";
        status[index] = true;
    } else {
        throw invalid_argument("La matrícula no existe");
    }
}

void HashTable::print() {
    for (const string& matricula : table) {
        if (!matricula.empty()) {
            cout << matricula << endl;
        }
    }
}

void HashTable::displayMenu() {
    // Implementación del menú en HashTable.h
    int choice;
    string matricula;

    do {
        cout << "Menú:\n";
        cout << "1. Insertar matrícula\n";
        cout << "2. Eliminar matrícula\n";
        cout << "3. Buscar matrícula\n";
        cout << "4. Mostrar lista de matrículas\n";
        cout << "0. Salir\n";

        cout << "Ingrese su opción: ";
        cin >> choice;

        // Declarar index fuera del switch
        int index = -1;

        switch (choice) {
            case 1:
                cout << "Ingrese la matrícula a insertar: ";
                cin >> matricula;
                insert(matricula);
                break;

            case 2:
                cout << "Ingrese la matrícula a eliminar: ";
                cin >> matricula;
                try {
                    remove(matricula);
                    cout << "Matrícula eliminada correctamente.\n";
                } catch (const invalid_argument &e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;

            case 3:
                cout << "Ingrese la matrícula a buscar: ";
                cin >> matricula;
                index = findData(matricula);
                if (index != -1) {
                    cout << "Matrícula encontrada en la posición " << index << endl;
                } else {
                    cout << "Matrícula no encontrada.\n";
                }
                break;

            case 4:
                print();
                break;

            case 0:
                cout << "Saliendo del programa.\n";
                break;

            default:
                cout << "Opción no válida. Por favor, intente de nuevo.\n";
        }

    } while (choice != 0);
}

#endif /* HashTable_h */
