//Programa de Rosendo De Los Rios Moreno A01198515
#include "LogEntry.h"    // Incluye el encabezado de la clase LogEntry
#include "BST.h"         // Incluye el encabezado de la clase BST
#include "MaxHeap.h" // Incluye el encabezado de la Maximo de Heap
#include "MinHeap.h"// Incluye el encabezado de la Minimo de Heap
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <limits> //Especifica limites 
using namespace std;

// Función para asegurarse de que la dirección IP tenga tres dígitos en cada segmento
string FormatIP(const string& ip) {
    vector<string> ipSegments;
    istringstream ipStream(ip);
    string ipSegment;
    while (getline(ipStream, ipSegment, '.')) {
        while (ipSegment.size() < 3) {
            ipSegment = "0" + ipSegment;
        }
        ipSegments.push_back(ipSegment);
    }
    return ipSegments[0] + "." + ipSegments[1] + "." + ipSegments[2] + "." + ipSegments[3];
}

// Función para comparar dos objetos LogEntry para ordenarlos
bool CompareLogEntries(const LogEntry& a, const LogEntry& b) {
    // Compara primero por dirección IP
    if (a.ip != b.ip) return a.ip > b.ip;

    // Luego, compara por año, mes, día y hora
    if (a.year != b.year) return a.year > b.year;
    if (a.month != b.month) return a.month > b.month;
    if (a.day != b.day) return a.day > b.day;
    if (a.time != b.time) return a.time > b.time;

    return false;
}

int main() {
    // Leer datos de log desde un archivo (log602-3.txt)
    vector<LogEntry> logData;
    ifstream file("log602-3.txt");
    if (file.is_open()) {
        LogEntry entry;
        // Leer datos de cada línea del archivo y almacenarlos en un vector de LogEntry
        while (file >> entry.month >> entry.day >> entry.year >> entry.time >> entry.ip) {
            getline(file, entry.message);
            entry.ip = FormatIP(entry.ip); // Formatear la IP
            logData.push_back(entry);
        }
        file.close();
    } else {
        cerr << "Error al abrir el archivo log602-3.txt" << endl;
        return 1;
    }

    int choice = 0;
    string searchIP;
    int result = 0;

    BST bst; // Crea un objeto de la clase BST (árbol binario de búsqueda)

    int count = 1;
    vector<pair<string, int>> ipCounts;
    ofstream maxHeapOut;
    ofstream minHeapOut;

    while (true) {
        // Menú de opciones para el usuario
        cout << "*************Menú de opciones*************" << endl;
        cout << "1. Ordenar los datos por IP, fecha y hora de mayor a menor" << endl;
        cout << "2. Ordenar los datos por IP, fecha y hora de menor a mayor" << endl;
        cout << "3. Mostrar las 10 IPs con mayor número de registros" << endl;
        cout << "4. Búsqueda de una IP en el archivo" << endl;
        cout << "5. Salir" << endl;
        cout << "Elija una opción: ";

        // Verifica que la entrada sea un número
        if (!(cin >> choice)) {
            cout << "Entrada inválida. Por favor, ingrese un número válido." << endl;
            cin.clear();  // Limpia los errores del flujo de entrada
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta la entrada incorrecta
            continue;  // Reinicia el ciclo
        }

        switch (choice) {
            case 1:
                // Ordena los datos por IP, fecha y hora de mayor a menor y los guarda en un archivo
                sort(logData.begin(), logData.end(), CompareLogEntries);
                maxHeapOut.open("output602-1.out");
                for (const LogEntry& entry : logData) {
                    maxHeapOut << entry.ip << ' ' << entry.year << ' ' << entry.month << ' ' << entry.day << ' ' << entry.time << ' ' << entry.message << endl;
                }
                maxHeapOut.close();
                cout << "Datos ordenados y guardados en output602-1.out." << endl;
                break;

            case 2:
                // Ordena los datos por IP, fecha y hora de menor a mayor y los guarda en un archivo
                sort(logData.begin(), logData.end(), CompareLogEntries);
                reverse(logData.begin(), logData.end());
                minHeapOut.open("output602-2.out");
                for (const LogEntry& entry : logData) {
                    minHeapOut << entry.ip << ' ' << entry.year << ' ' << entry.month << ' ' << entry.day << ' ' << entry.time << ' ' << entry.message << endl;
                }
                minHeapOut.close();
                cout << "Datos ordenados y guardados en output602-2.out." << endl;
                break;

            case 3:
                count = 1;
                ipCounts.clear();
                sort(logData.begin(), logData.end(), CompareLogEntries);
                // Cuenta cuántas veces se repite cada dirección IP y las almacena en ipCounts
                for (int i = 1; i < logData.size(); ++i) {
                    if (logData[i].ip == logData[i - 1].ip) {
                        count++;
                    } else {
                        ipCounts.push_back({logData[i - 1].ip, count});
                        count = 1;
                    }
                }
                ipCounts.push_back({logData.back().ip, count});
                // Ordena ipCounts por el número de registros en orden descendente
                sort(ipCounts.begin(), ipCounts.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
                    return a.second > b.second;
                });
                cout << "Las 10 IPs con más registros son:" << endl;
                // Muestra las 10 direcciones IP con más registros
                for (int i = 0; i < min(10, static_cast<int>(ipCounts.size())); ++i) {
                    cout << ipCounts[i].first << ": " << ipCounts[i].second << " registros" << endl;
                }
                break;

            case 4:
                cout << "Ingrese la dirección IP a buscar: ";
                cin >> searchIP;
                result = 0; // Inicializamos el resultado en 0

                // Utiliza la clase BST para buscar y contar las veces que aparece la IP
                result = bst.Search(searchIP);

                if (result > 0) {
                    cout << "La dirección IP '" << searchIP << "' se encontró " << result << " veces en el archivo." << endl;
                } else {
                    cout << "La dirección IP '" << searchIP << "' no se encontró en el archivo." << endl;
                }
                break;

            case 5:
                cout << "Fin del programa." << endl;
                return 0;

            default:
                cout << "Opción inválida. Seleccione una opción válida." << endl;
        }
    }

    return 0;
}
