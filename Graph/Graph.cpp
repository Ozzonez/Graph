#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "Graph.h"
#include "Vertex.h"

using namespace std;
template <typename T>
int Graph<T>::load()
{
    T a, b, c;
    int w;
    int number, nr2;
    fstream file;
    file.open("D.txt", ios::in);

    if(file.good()==false)
    {
        cout<<"Couldn't open the file!";
        exit(0);
    }

    file>>numVer;
    file>>numEdg;

    V = new Vertex<T> [numVer];
    cost = new int [numVer];
    predecessor = new int [numVer]; // CO Z TYM ????

    this->initialize();

    //for(int i=0;i<numEdg;i++)
    //while(file.eof()!=1)

    for(int i=0;i<numVer;i++)
    {
        file>>c;
        V[i].setMyVertex(c);
        V[i].setMyNumber(i); //setter!!!
    }



    for(int i=0;i<numEdg;i++)
    {


    file>>a;
    file>>b;
    file>>w;

    number=this->searchForNr(a);
    nr2=this->searchForNr(b);

    V[number].addNewElement(b, w, nr2);


    }

    return 1;
}
template <typename T>
Graph<T>::Graph()
{
    V=NULL;
    cost=NULL;
    predecessor=NULL;
}

template <typename T>
Graph<T>::~Graph()
{
    delete V;
    delete cost;
    delete predecessor;
}

template <typename T>
int Graph<T>::BF(T startingVertex)
{
    edge<T> *temp;
    int number;
    bool h;

    number=this->searchForNr(startingVertex);

    cost[number]=0;

    for(int i=1; i<numVer; i++)
    {
        h=true;
        for(int j=0; j<numVer; j++)
        {
            for(temp=V[j].getFirst(); temp!=NULL; temp=temp->next)
        {
            if(cost[temp->number_vertex]>cost[j]+temp->weight)
            {
                h=false;
                cost[temp->number_vertex]=cost[j]+temp->weight;
                predecessor[temp->number_vertex]=j;
            }
        }
        }
        if(h)
        return 1;
    }

    for(int j=0;j<numVer;j++)
    {
        for(temp=V[j].getFirst(); temp!=NULL; temp=temp->next)
        {
            if(cost[temp->number_vertex]>cost[j]+temp->weight)
                return 0;
        }
    }
    return 1;

}
template <typename T>
void Graph<T>::initialize()
{
    for(int i=0; i<numVer; i++)
    {
        cost[i]=100000000;
        predecessor[i]=-1;
    }
}


template <typename T>
int Graph<T>::searchForNr(T a)
{
    for(int i=0; i<numVer; i++)
    {
        if(V[i].getMyVertex()==a)
        {
            return i;
        }
    }
    exit(0); // Error in entering graph data
}



template <typename T>
int Graph<T>::getNumVer()
{
    return numVer;
}

template <typename T>
Vertex<T>* Graph<T>::getV()
{
    return V;
}

template <typename T>
int* Graph<T>::getPredecessor()
{
    return predecessor;
}

template <typename T>
int* Graph<T>::getCost()
{
    return cost;
}



template class Graph<int>;
template class Graph<double>;
template class Graph<string>;
template class Graph<char>;
