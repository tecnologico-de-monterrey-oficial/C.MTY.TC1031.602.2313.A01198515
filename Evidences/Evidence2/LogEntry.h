//Evidencia 2
//Rosendo Los Rios Moreno
//A01198515
#ifndef LOG_ENTRY_H
#define LOG_ENTRY_H
#include <string>
using namespace std;

// Definición de la estructura LogEntry para representar una entrada de registro
struct LogEntry {
    string month;   // Mes
    int day;        // Día
    int year;       // Año
    string time;    // Hora
    string ip;      // Dirección IP
    string message; // Mensaje
};

#endif // LOG_ENTRY_H