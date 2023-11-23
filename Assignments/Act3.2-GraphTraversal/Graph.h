#ifndef Graph_h
#define Graph_h

#include "Edge.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

template <class T>
class Graph {
private:
    std::vector<T> vertices;
    std::vector<std::vector<Edge<T>>> adjacencyList;
    int findVertex(T vertex);

public:
    Graph();
    Graph(std::vector<T> vertices, std::vector<Edge<T>> edges);
    void addVertex(T vertex);
    void addEdge(Edge<T> edge);
    void removeEdge(Edge<T> edge);
    void removeVertex(T vertex);
    void BFS(T startVertex);
    void DFS(T startVertex);
    void print();

    

private:
    void BFSUtil(int startVertex, std::vector<bool>& visited);
    void DFSUtil(int startVertex, std::vector<bool>& visited);
};

template<class T>
Graph<T>::Graph() {}

template<class T>
int Graph<T>::findVertex(T vertex) {
    auto it = std::find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return it - vertices.begin();
    } else {
        return -1;
    }
}

template<class T>
Graph<T>::Graph(std::vector<T> listVertices, std::vector<Edge<T>> edges) {
    vertices = listVertices;
    std::vector<Edge<T>> defaultEdges;
    adjacencyList.assign(vertices.size(), defaultEdges);

    for (const auto& edge : edges) {
        int sourceIndex = findVertex(edge.source);
        if (sourceIndex != -1) {
            adjacencyList[sourceIndex].push_back(edge);
        }
    }
}

template<class T>
void Graph<T>::addVertex(T vertex) {
    int place = findVertex(vertex);
    if (place == -1) {
        vertices.push_back(vertex);
        adjacencyList.emplace_back();
    } else {
        std::cout << "El vertice ya existe" << std::endl;
    }
}

template<class T>
void Graph<T>::addEdge(Edge<T> edge) {
    int sourceIndex = findVertex(edge.source);
    int targetIndex = findVertex(edge.target);

    if (sourceIndex != -1 && targetIndex != -1) {
        for (const auto& existingEdge : adjacencyList[sourceIndex]) {
            if (existingEdge.target == edge.target) {
                throw std::invalid_argument("El arco ya existe");
            }
        }
        adjacencyList[sourceIndex].push_back(edge);
    } else {
        throw std::invalid_argument("Alguno de los vértices no existe");
    }
}

template<class T>
void Graph<T>::removeVertex(T vertex) {
    int index = findVertex(vertex);
    if (index != -1) {
        vertices.erase(vertices.begin() + index);
        adjacencyList.erase(adjacencyList.begin() + index);

        for (auto& edges : adjacencyList) {
            edges.erase(std::remove_if(edges.begin(), edges.end(),
                [vertex](const Edge<T>& edge) { return edge.target == vertex; }),
                edges.end());
        }
    } else {
        throw std::invalid_argument("El vertice no existe");
    }
}

template<class T>
void Graph<T>::removeEdge(Edge<T> edge) {
    int sourceIndex = findVertex(edge.source);
    int targetIndex = findVertex(edge.target);
    if (sourceIndex != -1 && targetIndex != -1) {
        adjacencyList[sourceIndex].erase(std::remove_if(adjacencyList[sourceIndex].begin(), adjacencyList[sourceIndex].end(),
            [edge](const Edge<T>& e) { return e.target == edge.target; }),
            adjacencyList[sourceIndex].end());
    } else {
        throw std::invalid_argument("El arco no existe");
    }
}

template<class T>
void Graph<T>::print() {
    for (size_t i = 0; i < vertices.size(); ++i) {
        std::cout << vertices[i] << " - ";
        for (const auto& edge : adjacencyList[i]) {
            std::cout << "|" << edge.target << " " << edge.weight << "|" << " - ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template<class T>
void Graph<T>::BFS(T startVertex) {
    int startVertexIndex = findVertex(startVertex);
    if (startVertexIndex != -1) {
        std::vector<bool> visited(vertices.size(), false);
        BFSUtil(startVertexIndex, visited);
    } else {
        std::cout << "El vértice inicial no existe en el grafo." << std::endl;
    }
}

template<class T>
void Graph<T>::DFS(T startVertex) {
    int startVertexIndex = findVertex(startVertex);
    if (startVertexIndex != -1) {
        std::vector<bool> visited(vertices.size(), false);
        DFSUtil(startVertexIndex, visited);
    } else {
        std::cout << "El vértice inicial no existe en el grafo." << std::endl;
    }
}

template<class T>
void Graph<T>::BFSUtil(int startVertex, std::vector<bool>& visited) {
    std::queue<int> queue;
    visited[startVertex] = true;
    std::cout << vertices[startVertex] << " ";

    queue.push(startVertex);

    while (!queue.empty()) {
        int currentVertex = queue.front();
        queue.pop();

        for (const auto& edge : adjacencyList[currentVertex]) {
            int neighborIndex = findVertex(edge.target);
            if (!visited[neighborIndex]) {
                visited[neighborIndex] = true;
                std::cout << vertices[neighborIndex] << " ";
                queue.push(neighborIndex);
            }
        }
    }
    std::cout << std::endl;
}

template<class T>
void Graph<T>::DFSUtil(int startVertex, std::vector<bool>& visited) {
    std::stack<int> stack;
    visited[startVertex] = true;
    std::cout << vertices[startVertex] << " ";

    stack.push(startVertex);

    while (!stack.empty()) {
        int currentVertex = stack.top();
        stack.pop();

        for (const auto& edge : adjacencyList[currentVertex]) {
            int neighborIndex = findVertex(edge.target);
            if (!visited[neighborIndex]) {
                visited[neighborIndex] = true;
                std::cout << vertices[neighborIndex] << " ";
                stack.push(neighborIndex);
            }
        }
    }
    std::cout << std::endl;
}

#endif
