#include <iostream>
#include <fstream>
#include <sstream>
#include "LogEntry.h"
#include "DoublyLinkedList.h"

int main() {
    std::ifstream inputFile("log602-2.txt");
    DoublyLinkedList logEntries;

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 0;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string month, day, year, time, ip, message;
        iss >> month >> day >> year >> time >> ip;
        std::getline(iss, message);
        LogEntry entry(month + " " + day + " " + year, time, ip, message);
        logEntries.insert(entry);
    }

    inputFile.close();

    int choice;
    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Ordenar por fecha y hora" << std::endl;
        std::cout << "2. Ordenar por IP, fecha y hora" << std::endl;
        std::cout << "3. Búsqueda por rango de IP" << std::endl;
        std::cout << "4. Sumatoria de datos" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Ingrese su elección: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                logEntries.sort();
                std::cout << "Datos ordenados por fecha y hora." << std::endl;
                break;
            case 2:
                logEntries.sortByIP();
                std::cout << "Datos ordenados por IP, fecha y hora." << std::endl;
                break;
            case 3: {
                std::string startIP, endIP;
                std::cout << "Ingrese el rango de IP (inicio fin): ";
                std::cin >> startIP >> endIP;
                logEntries.searchByIPRange(startIP, endIP);
                std::cout << "Resultados de búsqueda guardados en archivos." << std::endl;
                break;
            }
            case 4:
                logEntries.sumByYearAndMonth();
                break;
            case 5:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Por favor, elija una opción válida." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
