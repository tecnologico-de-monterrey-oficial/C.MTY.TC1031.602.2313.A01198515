//Codigo Rosendo De Los Rios Moreno A01198515
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Log.h"

using namespace std;

int main() {
    ifstream fileIn("log602.txt");
    ofstream fileOut("output602.txt");
    string line;
    string word;
    string year, month, day, time, ip, message;
    vector<Log> logs;

    // Leer datos del archivo de entrada y almacenar en el vector logs
    while (getline(fileIn, line)) {
        stringstream ss(line);
        ss >> month >> day >> year >> time >> ip;
        getline(ss, message); // Leer el mensaje completo
        Log log(year, month, day, time, ip, message);
        logs.push_back(log);
    }

    // Ordenar los registros por fecha y hora usando el algoritmo de selección
    for (int i = 0; i < logs.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < logs.size(); j++) {
            if (logs[j] < logs[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(logs[i], logs[minIndex]);
        }
    }

    // Almacenar los registros ordenados en el archivo de salida
    for (const Log& log : logs) {
        fileOut << log.toCustomFormat() << endl;
    }

    // Búsqueda de un rango de datos
    string start_date, end_date, start_time, end_time;
    cout << "Ingrese fecha y hora de inicio (YYYY MM DD HH:MM:SS): ";
    cin >> start_date >> month >> day >> start_time;
    cout << "Ingrese fecha y hora de fin (YYYY MM DD HH:MM:SS): ";
    cin >> end_date >> month >> day >> end_time;

    // Crear archivo range602.txt y almacenar los registros del rango
    ofstream rangeOut("range602.txt");
    bool found = false; // Variable para verificar si se encontraron registros en el rango
    for (const Log& log : logs) {
        if (log.isInTimeRange(start_date, start_time, end_date, end_time)) {
            rangeOut << log.toCustomFormat() << endl;
            found = true; // Se encontró al menos un registro en el rango
        }
    }

    if (!found) {
        cout << "Ningún registro encontrado en el rango especificado." << endl;
    } else {
        cout << "Registros en el rango especificado han sido almacenados en range602.txt." << endl;
    }

    return 0;
}
