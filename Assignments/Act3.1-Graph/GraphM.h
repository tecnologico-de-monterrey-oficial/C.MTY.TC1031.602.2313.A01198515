#ifndef GraphM_h
#define GraphM_h

#include "Edge.h"
#include <vector>
#include <iostream>

template<class T>
class GraphM {
private:
    std::vector<T> vertices;
    std::vector<std::vector<int>> matrix;
    int findVertex(T vertex);

public:
    GraphM();
    GraphM(std::vector<T> listVertices, std::vector<Edge<T>> edges);
    void addVertex(T vertex);
    void addEdge(Edge<T> edge);
    void removeEdge(Edge<T> edge);
    void removeVertex(T vertex);
    void print();
};

template<class T>
GraphM<T>::GraphM() {}

template<class T>
int GraphM<T>::findVertex(T vertex) {
    auto it = std::find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1;
    }
}

template<class T>
GraphM<T>::GraphM(std::vector<T> listVertices, std::vector<Edge<T>> edges) {
    vertices = listVertices;
    std::vector<int> row(vertices.size(), 0);
    matrix.assign(vertices.size(), row);

    for (const auto& edge : edges) {
        int sourceIndex = findVertex(edge.source);
        int targetIndex = findVertex(edge.target);
        if (sourceIndex != -1 && targetIndex != -1) {
            matrix[sourceIndex][targetIndex] = edge.weight;
        }
    }
}

template<class T>
void GraphM<T>::addVertex(T vertex) {
    int place = findVertex(vertex);
    if (place == -1) {
        vertices.push_back(vertex);

        int size = matrix.size() + 1;
        for (auto& row : matrix) {
            row.push_back(0);
        }
        matrix.push_back(std::vector<int>(size, 0));
    } else {
        std::cout << "El vertice ya existe" << std::endl;
    }
}

template<class T>
void GraphM<T>::addEdge(Edge<T> edge) {
    int sourceIndex = findVertex(edge.source);
    int targetIndex = findVertex(edge.target);
    if (sourceIndex != -1 && targetIndex != -1) {
        matrix[sourceIndex][targetIndex] = edge.weight;
    } else {
        throw std::invalid_argument("Alguno de los vertices no existe");
    }
}

template<class T>
void GraphM<T>::removeVertex(T vertex) {
    int place = findVertex(vertex);
    if (place != -1) {
        vertices.erase(vertices.begin() + place);
        matrix.erase(matrix.begin() + place);

        for (auto& row : matrix) {
            row.erase(row.begin() + place);
        }
    } else {
        throw std::invalid_argument("El vertice no existe");
    }
}

template<class T>
void GraphM<T>::removeEdge(Edge<T> edge) {
    int sourceIndex = findVertex(edge.source);
    int targetIndex = findVertex(edge.target);
    if (sourceIndex != -1 && targetIndex != -1) {
        matrix[sourceIndex][targetIndex] = 0;
    } else {
        throw std::invalid_argument("Alguno de los vertices no existe");
    }
}

template<class T>
void GraphM<T>::print() {
    std::cout << "   ";
    for (const auto& vertex : vertices) {
        std::cout << " " << vertex;
    }
    std::cout << std::endl;
    for (size_t i = 0; i < vertices.size(); ++i) {
        std::cout << vertices[i] << " - ";
        for (size_t j = 0; j < vertices.size(); ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

#endif /* GraphM_h */
