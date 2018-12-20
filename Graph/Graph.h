#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "Vertex.h"
using namespace std;

template <typename T>
class Graph
{

    Vertex<T> *V;

    int *cost;
    int *predecessor;
    int numVer, numEdg;

    public:

    Graph();
    ~Graph();
    int load();
    void initialize();
    int BF(T);
    void BFCD(T);
    int searchForNr(T a);
    int getNumVer();
    Vertex<T>* getV();
    int* getPredecessor();
    int* getCost();



};

#endif // GRAPH_H
