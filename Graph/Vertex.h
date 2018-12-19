#ifndef VERTEX_H
#define VERTEX_H
#include <iostream>
using namespace std;

struct edge
    {
    edge * next;
    int vertex;
    int weight;
    };

class Vertex
{
    public:

    edge *first;

    public:

    void addNewElement(int, int);
    Vertex();
    //void setVertexAndWeight(int, int);


};

#endif // VERTEX_H
