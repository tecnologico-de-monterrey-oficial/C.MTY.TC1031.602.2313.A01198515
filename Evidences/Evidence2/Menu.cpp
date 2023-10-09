//Evidencia 2
//Rosendo Los Rios Moreno
//A01198515
#include <iostream>
#include "LogAnalyzer.h"
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main() {
    LogAnalyzer analyzer("log602-2.txt");
    int choice = 0;

    while (true) {
        cout << "*************Menú de opciones*****************" << endl;
        cout << "1. Ordenar los datos por fecha y hora" << endl;
        cout << "2. Ordenamiento IP, fecha y hora" << endl;
        cout << "3. Realizar búsqueda binaria por rango de IPs "<< endl;
        cout << "4. Mostrar Sumatoria de datos por año y mes" ""<< endl;
        cout << "5. Salir" << endl;
        cout << "Elija una opción: ";
        cin >> choice;

        switch (choice) {
            case 1:
                analyzer.SortDataByDate();
                break;

            case 2:
                analyzer.SortDataByIPDate();
                break;

            case 3: {
                string startIP, endIP;
                cout << "Introduce la IP completa para el inicio del rango: ";
                cin >> startIP;
                cout << "Introduce la IP completa para el fin del rango: ";
                cin >> endIP;
                list<LogEntry> logsInRange = analyzer.GetLogsInRange(startIP, endIP);
                analyzer.SaveLogsToFile(logsInRange, "iprange602-a.out");
                reverse(logsInRange.begin(), logsInRange.end()); // Reverse para obtener el orden descendente
                analyzer.SaveLogsToFile(logsInRange, "iprange602-d.out");
                break;
            }

            case 4: {
              analyzer.PrintSumDataByYearAndMonth();
                break;
            }

            case 5:
                cout << "Fin de el programa." << endl;
                return 0;

            default:
                cout << "Opion invalida. Seleccione una opion valida." << endl;
        }
    }

    return 0;
}

