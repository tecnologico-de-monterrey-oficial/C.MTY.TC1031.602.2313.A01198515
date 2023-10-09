//Evidencia 2
//Rosendo Los Rios Moreno
//A01198515
#ifndef LOG_ANALYZER_H
#define LOG_ANALYZER_H
#include <vector>
#include <string>
#include <list>
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

// Declaración de la clase LogAnalyzer
class LogAnalyzer {
public:
    // Constructor de la clase que recibe el nombre de un archivo de registro como parámetro
    LogAnalyzer(const string& filename);

    // Funciones públicas para realizar análisis y manipulación de registros
    void SortDataByDate();                 // Ordena los registros por fecha y hora
    void SortDataByIPDate();               // Ordena los registros por IP, fecha y hora
    list<LogEntry> GetLogsInRange(const string& startIP, const string& endIP); // Obtiene registros en un rango de IPs
    void PrintSumDataByYearAndMonth();     // Imprime la sumatoria de datos por año y mes
    void SaveLogsToFile(const list<LogEntry>& logs, const string& filename);  // Guarda registros en un archivo

private:
    vector<LogEntry> entries; // Almacena las entradas de registro en un vector privado

    // Función privada para leer las entradas de un archivo de registro
    void ReadLogEntries(const string& filename);
};

#endif // LOG_ANALYZER_H
