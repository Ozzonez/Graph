#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "Graph.h"
#include "Vertex.h"

using namespace std;

int Graph::load()
{

    int a, b, w;
    fstream file;
    file.open("D.txt", ios::in);

    if(file.good()==false)
    {
        cout<<"Couldn't open the file!";
        exit(0);
    }

    file>>numVer;
    file>>numEdg;

    V = new Vertex [numVer];
    cost = new int [numVer];
    predecessor = new int [numVer];

    this->initialize();

    //for(int i=0;i<numEdg;i++)
    //while(file.eof()!=1)
    for(int i=0;i<numEdg;i++)
    {


    file>>a;
    file>>b;
    file>>w;

    V[a].addNewElement(b, w);


    }

    return 1;
}

Graph::Graph()
{
    V = NULL;
    cost=NULL;
    predecessor=NULL;



}

int Graph::BF(int startingVertex)
{
    edge *temp;
    cost[startingVertex]=0;


    for(int i=0; i<numVer; i++)
    {
        for(int j=0; j<numVer; j++)
        {
            for(temp=V[j].first/*trzeba gettera*/; temp!=NULL; temp=temp->next)
        {
            if(cost[temp->vertex]>cost[j]+temp->weight)
            {
                cost[temp->vertex]=cost[j]+temp->weight;
                predecessor[temp->vertex]=j;
            }
        }
        }

    }



    for(int j=0;j<numVer;j++)
    {
        for(temp=V[j].first; temp!=NULL; temp=temp->next)
        {
            if(cost[temp->vertex]>cost[j]+temp->weight)
                return 0;
        }
    }











}

void Graph::initialize()
{
    for(int i=0; i<numVer; i++)
    {
        cost[i]=100000000;
        predecessor[i]=-1;
    }
}
