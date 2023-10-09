//Evidencia 2
//Rosendo Los Rios Moreno
//A01198515
#include "LogAnalyzer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

// Constructor de la clase LogAnalyzer
LogAnalyzer::LogAnalyzer(const string& filename) {
    ReadLogEntries(filename); // Llama a la función para leer las entradas del archivo
}

// Función para leer las entradas del archivo de registro
void LogAnalyzer::ReadLogEntries(const string& filename) {
    ifstream file(filename); // Abre el archivo
    string line;

    while (getline(file, line)) { // Lee cada línea del archivo
        LogEntry entry;
        istringstream iss(line);
        iss >> entry.month >> entry.day >> entry.year >> entry.time >> entry.ip; // Lee los campos de la entrada
        getline(iss, entry.message); // Lee el mensaje restante
        entries.push_back(entry); // Agrega la entrada a la lista de entradas
    }

    file.close(); // Cierra el archivo
}

// Función para ordenar los datos por fecha y hora
void LogAnalyzer::SortDataByDate() {
    sort(entries.begin(), entries.end(), [](const LogEntry& a, const LogEntry& b) {
        map<string, int> monthOrder = {{"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}};
        if (a.year != b.year) {
            return a.year < b.year;
        }
        if (monthOrder[a.month] != monthOrder[b.month]) {
            return monthOrder[a.month] < monthOrder[b.month];
        }
        if (a.day != b.day) {
            return a.day < b.day;
        }
        return a.time < b.time;
    });

    ofstream outputFile("output602-1.out"); // Abre el archivo de salida
    if (!outputFile) {
        cerr << "Error: fallo al generar el archivo output602-1.out" << endl; // Mensaje de error si no se pudo abrir el archivo
        return;
    }

    for (const LogEntry& entry : entries) { // Escribe las entradas ordenadas en el archivo de salida
        outputFile << entry.month << " " << entry.day << " " << entry.year << " " << entry.time << " "
                   << entry.ip << " " << entry.message << endl;
    }

    outputFile.close(); // Cierra el archivo de salida
    cout << "Archivo output602-1.out fue generado de manera correcta" << endl; // Mensaje de éxito
}

// Función para ordenar los datos por IP, fecha y hora
void LogAnalyzer::SortDataByIPDate() {
    sort(entries.begin(), entries.end(), [](const LogEntry& a, const LogEntry& b) {
        if (a.ip != b.ip) {
            return a.ip < b.ip;
        }
        if (a.year != b.year) {
            return a.year < b.year;
        }
        map<string, int> monthOrder = {{"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}};
        if (monthOrder[a.month] != monthOrder[b.month]) {
            return monthOrder[a.month] < monthOrder[b.month];
        }
        if (a.day != b.day) {
            return a.day < b.day;
        }
        return a.time < b.time;
    });

    ofstream outputFile("output602-2.out"); // Abre el archivo de salida
    if (!outputFile) {
        cerr << "Error: fallo al generar el archivo output602-2.out" << endl; // Mensaje de error si no se pudo abrir el archivo
        return;
    }

    for (const LogEntry& entry : entries) { // Escribe las entradas ordenadas en el archivo de salida
        outputFile << entry.ip << " " << entry.month << " " << entry.day << " " << entry.year << " " << entry.time << " "
                   << entry.message << endl;
    }

    outputFile.close(); // Cierra el archivo de salida
    cout << "Archivo output602-2.out fue generado de manera correcta." << endl; // Mensaje de éxito
}

// Función para obtener las entradas en un rango de IPs
list<LogEntry> LogAnalyzer::GetLogsInRange(const string& startIP, const string& endIP) {
    list<LogEntry> result;
    for (const LogEntry& entry : entries) { // Itera a través de las entradas
        if (entry.ip >= startIP && entry.ip <= endIP) { // Comprueba si la IP está en el rango especificado
            result.push_back(entry); // Agrega la entrada al resultado
        }
    }
    return result; // Devuelve la lista de entradas en el rango
}

// Función para imprimir la sumatoria de datos por año y mes
void LogAnalyzer::PrintSumDataByYearAndMonth() {
    map<string, int> sumatoria_por_anio_mes;

    for (const LogEntry& entry : entries) { // Itera a través de las entradas
        string anio_mes = to_string(entry.year) + " " + entry.month;
        sumatoria_por_anio_mes[anio_mes]++; // Incrementa la sumatoria para el año y mes correspondientes
    }

    // Ordenar el mapa por clave (que incluye año y mes)
    vector<pair<string, int>> sorted_sumatoria(sumatoria_por_anio_mes.begin(), sumatoria_por_anio_mes.end());
    sort(sorted_sumatoria.begin(), sorted_sumatoria.end());

    for (const auto& entry : sorted_sumatoria) { // Itera a través de las sumatorias ordenadas
        cout << "Año y Mes  " << entry.first << "  " << "Total de IPs: " << entry.second << endl; // Imprime la sumatoria
    }
}

// Función para guardar las entradas en un archivo
void LogAnalyzer::SaveLogsToFile(const list<LogEntry>& logs, const string& filename) {
    ofstream outputFile(filename); // Abre el archivo de salida
    if (!outputFile) {
        cerr << "Error: Archivo no encontrado" << filename << endl; // Mensaje de error si no se pudo abrir el archivo
        return;
    }

    for (const LogEntry& entry : logs) { // Escribe las entradas en el archivo de salida
        outputFile << entry.month << " " << entry.day << " " << entry.year << " " << entry.time << " "
                   << entry.ip << " " << entry.message << endl;
    }
    outputFile.close(); // Cierra el archivo de salida
    cout << "Archivo " << filename << " fue generado de manera correcta" << endl; // Mensaje de éxito
}
