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
    ancestor = new int [numVer];



    //for(int i=0;i<numEdg;i++)
    while(file.eof())
    {


    file>>a>>b>>w;

    V[a].addNewElement(b, w);


    }

    return 1;
}

Graph::Graph()
{
    V = NULL;
    cost=NULL;
    ancestor=NULL;



}
