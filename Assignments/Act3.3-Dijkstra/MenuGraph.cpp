#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits> // Para limpiar el buffer de entrada

#include "Graph.h"
#include "GraphM.h"

int obtenerOpcion() {
    std::cout << "Ingrese su opción: ";
    int opcion;
    while (!(std::cin >> opcion)) {
        std::cin.clear(); // Limpiar el estado de error
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar la entrada no válida
        std::cout << "Entrada no válida. Por favor, ingrese un número: ";
    }
    return opcion;
}

int main() {
    // Creacion de grafo default con vertices y sus edges
    std::vector<int> vertices = {0, 1, 2, 3, 4, 5, 6, 7};
    std::vector<Edge<int>> edges;
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
    
    // Constructores de graphM y graph
    Graph<int> graph(vertices, edges);
    GraphM<int> graphM(vertices, edges);

    int vertice;
    int source, target, weight;
    bool seguir = true;
    int opcion;

    while (seguir) {
        std::cout << "----------Menu----------" << std::endl;
        std::cout << "Seleccione la opción que desea hacer" << std::endl;
        std::cout << "1. Agregar vértice" << std::endl;
        std::cout << "2. Agregar arco" << std::endl;
        std::cout << "3. Eliminar vértice" << std::endl;
        std::cout << "4. Eliminar arco" << std::endl;
        std::cout << "5. Imprimir grafo" << std::endl;
        std::cout << "6. Recorrido BFS" << std::endl;
        std::cout << "7. Recorrido DFS" << std::endl;
        std::cout << "8. Dijkstra Shortest Path" << std::endl;  // Nueva opción
        std::cout << "9. Salir" << std::endl;

        opcion = obtenerOpcion();

        switch (opcion) {
            case 1:
                std::cout << "Ingrese el vértice que desea agregar: ";
                std::cin >> vertice;
                graph.addVertex(vertice);
                graphM.addVertex(vertice);
                std::cout << "Vértice agregado exitosamente." << std::endl;
                break;
            case 2:
                std::cout << "Ingrese el arco que desea agregar con formato (source, target, weight)" << std::endl;
                std::cout << "Ingrese el source: ";
                std::cin >> source;
                std::cout << "Ingrese el target: ";
                std::cin >> target;
                std::cout << "Ingrese el weight: ";
                std::cin >> weight;
                graph.addEdge(Edge<int>(source, target, weight));
                graphM.addEdge(Edge<int>(source, target, weight));
                std::cout << "Arco agregado exitosamente." << std::endl;
                break;
            case 3:
                std::cout << "Ingrese el vértice que desea eliminar: ";
                std::cin >> vertice;
                graph.removeVertex(vertice);
                graphM.removeVertex(vertice);
                std::cout << "Vértice eliminado exitosamente." << std::endl;
                break;
            case 4:
                std::cout << "Ingrese el arco que desea eliminar con formato (source, target): ";
                std::cin >> source >> target;
                graph.removeEdge(Edge<int>(source, target));
                graphM.removeEdge(Edge<int>(source, target));
                std::cout << "Arco eliminado exitosamente." << std::endl;
                break;
            case 5:
                std::cout << "Matriz de adyacencias:" << std::endl;
                graphM.print();
                std::cout << "Lista de adyacencias:" << std::endl;
                graph.print();
                break;
            case 6:
                std::cout << "Ingrese el vértice inicial para el recorrido BFS: ";
                std::cin >> vertice;
                graph.BFS(vertice);
                break;
            case 7:
                std::cout << "Ingrese el vértice inicial para el recorrido DFS: ";
                std::cin >> vertice;
                graph.DFS(vertice);
                break;
            case 8:
                std::cout << "Ingrese el vértice inicial para el recorrido Dijkstra: ";
                std::cin >> vertice;
                graph.dijkstra(vertice);
                break;
            case 9:
                std::cout << "Saliendo..." << std::endl;
                seguir = false;
                break;
            default:
                std::cout << "Opción no válida. Por favor, seleccione una opción del menú." << std::endl;
                break;
        }
    }

    return 0;
}
