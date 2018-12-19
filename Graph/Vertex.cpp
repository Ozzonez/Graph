#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "Vertex.h"

using namespace std;

void Vertex::addNewElement(int a, int b)
{

    edge *newEl;


    newEl = new edge;
    newEl->vertex = a;
    newEl->weight = b;

    if(first==NULL)
    {

        first=newEl;
        first->next=NULL;
    }
    else
    {
        edge *temp = first;

        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newEl;
        newEl->next = NULL;
    }


}


Vertex::Vertex()
{
    //first->next=NULL;
    first=NULL;

}
