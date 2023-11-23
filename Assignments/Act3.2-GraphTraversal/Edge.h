#pragma once

template<class T>
struct Edge{
    T source;
    T target;
    int weight;

    Edge();
    Edge(T source, T target); // Normal
    Edge(T source, T target, int weight); // Se usa cuando los vertices estan ponderados
};

template<class T>

Edge<T>::Edge(){
    this->weight = 0;
}

template<class T>
Edge<T>::Edge(T source, T target){
    this->source = source;
    this->target = target;
    this->weight = 0;
}

template<class T>
Edge<T>::Edge(T source, T target, int weight){
    this->source = source;
    this->target = target;
    this->weight = weight;
}