#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "GraphM.h"
#include "Graph.h"

int main() {
    vector<int> verticesG = {0, 1, 2, 3, 4, 5, 6, 7};

    vector<Edge<int>> edges;
    edges.emplace_back(0, 2, 9);
    edges.emplace_back(0, 3, 9);
    edges.emplace_back(1, 0, 7);
    edges.emplace_back(2, 0, 7);
    edges.emplace_back(2, 1, 5);
    edges.emplace_back(2, 6, 7);
    edges.emplace_back(3, 1, 8);
    edges.emplace_back(3, 7, 1);
    edges.emplace_back(4, 2, 7);
    edges.emplace_back(4, 6, 9);
    edges.emplace_back(5, 1, 1);
    edges.emplace_back(5, 3, 9);
    edges.emplace_back(6, 4, 3);
    edges.emplace_back(7, 5, 2);

    GraphM<int> graphM({}, edges);
    Graph<int> graphG(verticesG, edges);

    int option;
    do {
        cout << "\nMenu:\n";
        cout << "1. Agregar vértice\n";
        cout << "2. Agregar arco\n";
        cout << "3. Eliminar vértice\n";
        cout << "4. Eliminar arco\n";
        cout << "5. Mostrar grafo con matriz de adyacencia\n";
        cout << "6. Mostrar grafo con lista de adyacencia\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> option;

        switch (option) {
            case 1: {
                int vertex;
                cout << "Ingrese el vértice a agregar: ";
                cin >> vertex;
                graphG.addVertex(vertex);
                break;
            }
            case 2: {
                int start, end, weight;
                cout << "Ingrese el arco (inicio fin peso): ";
                cin >> start >> end >> weight;
                graphG.addEdge(Edge<int>(start, end, weight));
                break;
            }
            case 3: {
                int vertex;
                cout << "Ingrese el vértice a eliminar: ";
                cin >> vertex;
                graphG.removeVertex(vertex);
                break;
            }
            case 4: {
                int start, end;
                cout << "Ingrese el arco a eliminar (inicio fin): ";
                cin >> start >> end;
                graphG.removeEdge(Edge<int>(start, end));
                break;
            }
            case 5:
                cout << "\nGrafo con matriz de adyacencia:\n";
                graphM.print();
                break;
            case 6:
                cout << "\nGrafo con lista de adyacencia:\n";
                graphG.print();
                break;
            case 7:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (option != 7);

    return 0;