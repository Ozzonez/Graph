#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "Vertex.h"
using namespace std;


class Graph
{
    public:
    Vertex *V;

    int *cost;
    int *predecessor;
    int numVer, numEdg;

    public:

    Graph();

    int load();
    void initialize();
    int BF(int);


};

#endif // GRAPH_H
