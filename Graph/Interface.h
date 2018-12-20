#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include "Graph.h"
#include "Vertex.h"

using namespace std;

template <typename T>
class Interface
{
    int help;

    public:
    void mainMenu(Graph<T>);
};




#endif // VERTEX_H
