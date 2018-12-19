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
    int *ancestor;
    int numVer, numEdg;

    public:

    Graph();

    int load();



};

#endif // GRAPH_H
