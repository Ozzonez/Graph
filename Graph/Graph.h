#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "Vertex.h"
using namespace std;

template <typename T>
class Graph
{
    //public:
    Vertex<T> *V;

    int *cost;
    int *predecessor;
    int numVer, numEdg;

    public:

    Graph();

    int load();
    void initialize();
    int BF(T);
    int searchForNr(T a);


};

#endif // GRAPH_H
