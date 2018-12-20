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
//Class that holds vertex's number and neighbours
template <typename T>
class Vertex
{

    T myVertex;
    int myNumber;
    edge <T> *first;

    public:


    void addNewElement(T, int, int);
    Vertex();
    ~Vertex();
    void setMyVertex(T);
    edge<T>* getFirst();
    T getMyVertex();
    void setMyNumber(int);
    int getWeight();
    int getNumber_vertex();

};

#endif // VERTEX_H
