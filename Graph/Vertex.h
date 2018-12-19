#ifndef VERTEX_H
#define VERTEX_H
#include <iostream>
using namespace std;

template <typename T>
struct edge
    {
    edge * next;
    T vertex;
    int weight;
    int number_vertex;
    };

template <typename T>
class Vertex
{
    public:

    T myVertex;
    int myNumber;
    edge <T> *first;

    public:


    void addNewElement(T, int, int);
    Vertex();
    //void setVertexAndWeight(int, int);


};

#endif // VERTEX_H
