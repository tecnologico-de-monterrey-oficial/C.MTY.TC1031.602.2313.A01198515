#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;

struct Edge {
    string origen;
    string destino;
    int tiempoTren;
    int distanciaTren;
    int tiempoCarro;
    int distanciaCarro;

    Edge(string o, string d, int tt, int td, int tc, int dc)
        : origen(o), destino(d), tiempoTren(tt), distanciaTren(td), tiempoCarro(tc), distanciaCarro(dc) {}
};

class Grafo {
public:
    void agregarArista(const Edge& arista);
    const unordered_set<string>& getCiudades() const;
    void imprimirGrafo() const;
    pair<pair<double, int>, string> dijkstra(const string& inicio, const string& fin, const string& modo);
    string formatTime(int minutos) const;
    vector<string> obtenerCiudadesOrdenadas() const;
    void imprimirListaAdyacenciaArchivo(const string& nombreArchivo) const;
    void recorridoBFS(const string& inicio) const;
    void recorridoDFS(const string& inicio, ofstream& archivoDFS) const;
    void recorridoDFS(const string& inicio) const;
    void imprimirDFSArchivo(const string& nombreArchivo) const;
    void recorridoBFSArchivo(const string& inicio, ofstream& archivoBFS) const;
    void recorridoDFSArchivo(const string& inicio, ofstream& archivoDFS) const;

private:
    unordered_map<string, vector<Edge>> listaAdyacencia;
    unordered_set<string> ciudades;
};


void Grafo::agregarArista(const Edge& arista) {
    listaAdyacencia[arista.origen].push_back(arista);
    ciudades.insert(arista.origen);
    ciudades.insert(arista.destino);
}

const unordered_set<string>& Grafo::getCiudades() const {
    return ciudades;
}

void Grafo::imprimirGrafo() const {
    for (const auto& par : listaAdyacencia) {
        for (const auto& arista : par.second) {
            cout << arista.origen << " a " << arista.destino << endl;
            cout << "Distancia Tren: " << arista.distanciaTren << " km" << endl;
            cout << "Tiempo Tren: " << formatTime(arista.tiempoTren) << endl;
            cout << "Distancia Carro: " << arista.distanciaCarro << " km" << endl;
            cout << "Tiempo Carro: " << formatTime(arista.tiempoCarro) << endl;
            cout << "-----" << endl;
        }
    }
}

pair<pair<double, int>, string> Grafo::dijkstra(const string& inicio, const string& fin, const string& modo) {
    unordered_map<string, double> distancias;
    unordered_map<string, int> tiempos;
    unordered_map<string, string> anterior;
    priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> colaPrioridad;

    for (const auto& ciudad : ciudades) {
        distancias[ciudad] = numeric_limits<double>::infinity();
        tiempos[ciudad] = numeric_limits<int>::max();
    }

    distancias[inicio] = 0.0;
    tiempos[inicio] = 0;
    colaPrioridad.push({0.0, inicio});

    while (!colaPrioridad.empty()) {
        auto [distActual, ciudadActual] = colaPrioridad.top();
        colaPrioridad.pop();

        if (ciudadActual == fin) {
            string camino = fin;
            while (anterior[ciudadActual] != "") {
                camino = anterior[ciudadActual] + " -> " + camino;
                ciudadActual = anterior[ciudadActual];
            }
            return {{distancias[fin], tiempos[fin]}, camino};
        }

        for (const auto& arista : listaAdyacencia[ciudadActual]) {
            double distVecino = (modo == "tren") ? arista.distanciaTren : arista.distanciaCarro;
            int tiempoVecino = (modo == "tren") ? arista.tiempoTren : arista.tiempoCarro;
            double altDistancia = distancias[ciudadActual] + distVecino;
            int altTiempo = tiempos[ciudadActual] + tiempoVecino;

            if (altTiempo < tiempos[arista.destino] || (altTiempo == tiempos[arista.destino] && altDistancia < distancias[arista.destino])) {
                distancias[arista.destino] = altDistancia;
                tiempos[arista.destino] = altTiempo;
                anterior[arista.destino] = ciudadActual;
                colaPrioridad.push({altDistancia, arista.destino});
            }
        }
    }

    return {{numeric_limits<double>::infinity(), numeric_limits<int>::max()}, ""};
}

string Grafo::formatTime(int minutos) const {
    int horas = minutos / 60;
    int mins = minutos % 60;
    stringstream ss;
    ss << horas << "h " << mins << "m";
    return ss.str();
}

vector<string> Grafo::obtenerCiudadesOrdenadas() const {
    vector<string> ciudadesOrdenadas(ciudades.begin(), ciudades.end());
    sort(ciudadesOrdenadas.begin(), ciudadesOrdenadas.end());
    return ciudadesOrdenadas;
}

void Grafo::imprimirListaAdyacenciaArchivo(const string& nombreArchivo) const {
    ofstream archivoSalida(nombreArchivo);
    if (!archivoSalida.is_open()) {
        cerr << "Error al abrir el archivo de salida." << endl;
        return;
    }

    for (const auto& par : listaAdyacencia) {
        archivoSalida << par.first << ": ";
        for (const auto& arista : par.second) {
            archivoSalida << arista.destino << ", ";
        }
        archivoSalida << "\n";
    }

    archivoSalida.close();
    cout << "Lista de adyacencia ha sido escrita en " << nombreArchivo << endl;
}

void Grafo::recorridoBFS(const string& inicio) const {
    unordered_set<string> visitados;
    queue<string> cola;

    cola.push(inicio);
    visitados.insert(inicio);

    cout << "Recorrido BFS desde " << inicio << ":\n";
    while (!cola.empty()) {
        string actual = cola.front();
        cola.pop();
        cout << actual << " ";

        for (const auto& vecino : listaAdyacencia.at(actual)) {
            if (visitados.find(vecino.destino) == visitados.end()) {
                cola.push(vecino.destino);
                visitados.insert(vecino.destino);
            }
        }
    }
    cout << endl;
}

void Grafo::recorridoDFS(const string& inicio, ofstream& archivoDFS) const {
    unordered_set<string> visitados;
    stack<string> pila;

    pila.push(inicio);
    visitados.insert(inicio);

    while (!pila.empty()) {
        string actual = pila.top();
        pila.pop();
        archivoDFS << actual << " ";

        for (const auto& vecino : listaAdyacencia.at(actual)) {
            if (visitados.find(vecino.destino) == visitados.end()) {
                pila.push(vecino.destino);
                visitados.insert(vecino.destino);
            }
        }
    }
}

void Grafo::recorridoDFS(const string& inicio) const {
    unordered_set<string> visitados;
    stack<string> pila;

    pila.push(inicio);
    visitados.insert(inicio);

    cout << "Recorrido DFS desde " << inicio << ":\n";
    while (!pila.empty()) {
        string actual = pila.top();
        pila.pop();
        cout << actual << " ";

        for (const auto& vecino : listaAdyacencia.at(actual)) {
            if (visitados.find(vecino.destino) == visitados.end()) {
                pila.push(vecino.destino);
                visitados.insert(vecino.destino);
            }
        }
    }
    cout << endl;
}

void Grafo::imprimirDFSArchivo(const string& nombreArchivo) const {
    ofstream archivoDFS(nombreArchivo);
    if (archivoDFS.is_open()) {
        for (const auto& par : listaAdyacencia) {
            recorridoDFS(par.first, archivoDFS);
        }
        archivoDFS.close();
        cout << "Recorrido DFS ha sido escrito en " << nombreArchivo << endl;
    } else {
        cerr << "Error al abrir el archivo de salida para DFS.\n";
    }
}

void Grafo::recorridoBFSArchivo(const string& inicio, ofstream& archivoBFS) const {
    unordered_set<string> visitados;
    queue<string> cola;

    cola.push(inicio);
    visitados.insert(inicio);

    while (!cola.empty()) {
        string actual = cola.front();
        cola.pop();
        archivoBFS << actual << " ";

        for (const auto& vecino : listaAdyacencia.at(actual)) {
            if (visitados.find(vecino.destino) == visitados.end()) {
                cola.push(vecino.destino);
                visitados.insert(vecino.destino);
            }
        }
    }
}

void Grafo::recorridoDFSArchivo(const string& inicio, ofstream& archivoDFS) const {
    unordered_set<string> visitados;
    stack<string> pila;

    pila.push(inicio);
    visitados.insert(inicio);

    while (!pila.empty()) {
        string actual = pila.top();
        pila.pop();
        archivoDFS << actual << " ";

        for (const auto& vecino : listaAdyacencia.at(actual)) {
            if (visitados.find(vecino.destino) == visitados.end()) {
                pila.push(vecino.destino);
                visitados.insert(vecino.destino);
            }
        }
    }
}

#endif
