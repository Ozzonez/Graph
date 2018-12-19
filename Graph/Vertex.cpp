#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "Vertex.h"
#include "Graph.h"

using namespace std;
template <typename T>
void Vertex<T>::addNewElement(T b, int w, int nr)
{

    edge<T> *newEl;


    newEl = new edge<T>;
    newEl->vertex = b;
    newEl->weight = w;
    newEl->number_vertex=nr;

    if(first==NULL)
    {

        first=newEl;
        first->next=NULL;
    }
    else
    {
        edge<T> *temp = first;

        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newEl;
        newEl->next = NULL;
    }


}

template <typename T>
Vertex<T>::Vertex()
{
    //first->next=NULL;
    first=NULL;

}

template class Vertex<int>;
template class Vertex<double>;
template class Vertex<string>;
template class Vertex<char>;
