#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include "Grafo.h"

int convertirTiempoAMinutos(const string& tiempo) {
    stringstream ss(tiempo);
    int horas, minutos;
    char dosPuntos;
    ss >> horas >> dosPuntos >> minutos;
    return horas * 60 + minutos;
}

string toLowerCase(const string& input) {
    string result = input;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int main() {
    ifstream archivoEntrada("EuropeCities.csv");

    if (!archivoEntrada.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    string linea;
    getline(archivoEntrada, linea); // Saltar la cabecera

    Grafo grafo;

    while (getline(archivoEntrada, linea)) {
        istringstream ss(linea);
        string origen, destino, tiempoTren, distanciaTren, tiempoCarro, distanciaCarro;

        getline(ss, origen, ',');
        getline(ss, destino, ',');
        getline(ss, tiempoTren, ',');
        getline(ss, distanciaTren, ',');
        getline(ss, tiempoCarro, ',');
        getline(ss, distanciaCarro, ',');

        int tt = convertirTiempoAMinutos(tiempoTren);
        int dt = stoi(distanciaTren);
        int tc = convertirTiempoAMinutos(tiempoCarro);
        int dc = stoi(distanciaCarro);

        origen = toLowerCase(origen);
        destino = toLowerCase(destino);

        Edge arista(origen, destino, tt, dt, tc, dc);
        grafo.agregarArista(arista);
    }

    archivoEntrada.close();

    int opcion;
    do {
        cout << "\nMenu:\n";
        cout << "1. Generar archivo de salida para ciudades ordenadas\n";
        cout << "2. Generar archivo de salida para lista de adyacencia\n";
        cout << "3. Desplegar recorridos del grafo y generar archivos de salida\n";
        cout << "4. Calcular y mostrar ruta más corta en Tren\n";
        cout << "5. Calcular y mostrar ruta más corta en Carro\n";
        cout << "6. Salir\n";
        cout << "Ingresa tu opción: ";

        // Verificar si la entrada es un número
        if (!(cin >> opcion)) {
            cout << "Error: Debes ingresar un número.\n";
            cin.clear();  // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada no válida
            continue;  // Saltar la iteración actual
        }

        switch (opcion) {
            case 1: {
                auto ciudadesOrdenadas = grafo.obtenerCiudadesOrdenadas();
                ofstream archivoCiudadesOrdenadas("output602-1.out");
                if (archivoCiudadesOrdenadas.is_open()) {
                    for (const auto& ciudad : ciudadesOrdenadas) {
                        archivoCiudadesOrdenadas << ciudad << endl;
                    }
                    archivoCiudadesOrdenadas.close();
                    cout << "Ciudades ordenadas han sido escritas en output602-1.out\n";
                } else {
                    cerr << "Error al abrir el archivo de salida.\n";
                }
                break;
            }
            case 2: {
                grafo.imprimirListaAdyacenciaArchivo("output602-2.out");
                break;
            }
            case 3: {
                string ciudadInicio;
                cout << "\nIngresa la ciudad de inicio para los recorridos: ";
                cin >> ciudadInicio;

                ciudadInicio = toLowerCase(ciudadInicio);

                // Verificar si la ciudad existe en el grafo
                if (grafo.getCiudades().find(ciudadInicio) == grafo.getCiudades().end()) {
                    cout << "Error: La ciudad no existe en el grafo." << endl;
                    break;
                }

                // Recorrido BFS
                ofstream archivoBFS("output602-3.out");
                if (archivoBFS.is_open()) {
                    grafo.recorridoBFSArchivo(ciudadInicio, archivoBFS);
                    archivoBFS.close();
                    cout << "Recorrido BFS ha sido escrito en output602-3.out\n";
                } else {
                    cerr << "Error al abrir el archivo de salida para BFS.\n";
                }

                // Recorrido DFS
                ofstream archivoDFS("output602-4.out");
                if (archivoDFS.is_open()) {
                    grafo.recorridoDFSArchivo(ciudadInicio, archivoDFS);
                    archivoDFS.close();
                    cout << "Recorrido DFS ha sido escrito en output602-4.out\n";
                } else {
                    cerr << "Error al abrir el archivo de salida para DFS.\n";
                }
                break;
            }
            case 4: {
                // Calcular y mostrar la ruta más rápida en tren
                string ciudadInicio, ciudadFin;
                cout << "\nIngresa la ciudad de inicio: ";
                cin >> ciudadInicio;
                cout << "Ingresa la ciudad de destino: ";
                cin >> ciudadFin;

                ciudadInicio = toLowerCase(ciudadInicio);
                ciudadFin = toLowerCase(ciudadFin);

                // Verificar si las ciudades existen en el grafo
                if (grafo.getCiudades().find(ciudadInicio) == grafo.getCiudades().end() ||
                    grafo.getCiudades().find(ciudadFin) == grafo.getCiudades().end()) {
                    cout << "Error: Al menos una de las ciudades no existe en el grafo." << endl;
                    break;
                }

                auto resultadoTren = grafo.dijkstra(ciudadInicio, ciudadFin, "tren");
                cout << "\nRuta más rápida en tren:" << endl;
                cout << "Distancia: " << resultadoTren.first.first << " km" << endl;
                cout << "Tiempo: " << grafo.formatTime(resultadoTren.first.second) << endl;
                cout << "Camino: " << resultadoTren.second << endl;
                break;
            }
            case 5: {
                // Calcular y mostrar la ruta más rápida en carro
                string ciudadInicio, ciudadFin;
                cout << "\nIngresa la ciudad de inicio: ";
                cin >> ciudadInicio;
                cout << "Ingresa la ciudad de destino: ";
                cin >> ciudadFin;

                ciudadInicio = toLowerCase(ciudadInicio);
                ciudadFin = toLowerCase(ciudadFin);

                // Verificar si las ciudades existen en el grafo
                if (grafo.getCiudades().find(ciudadInicio) == grafo.getCiudades().end() ||
                    grafo.getCiudades().find(ciudadFin) == grafo.getCiudades().end()) {
                    cout << "Error: Al menos una de las ciudades no existe en el grafo." << endl;
                    break;
                }

                auto resultadoCarro = grafo.dijkstra(ciudadInicio, ciudadFin, "carro");
                cout << "\nRuta más rápida en carro:" << endl;
                cout << "Distancia: " << resultadoCarro.first.first << " km" << endl;
                cout << "Tiempo: " << grafo.formatTime(resultadoCarro.first.second) << endl;
                cout << "Camino: " << resultadoCarro.second << endl;
                break;
            }
            case 6: {
                cout << "Saliendo del programa.\n";
                break;
            }
            default: {
                cout << "Opción no válida. Por favor, elige una opción del menú.\n";
                break;
            }
        }
    } while (opcion != 6);

    return 0;
}
