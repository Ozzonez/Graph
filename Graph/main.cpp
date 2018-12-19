#include <iostream>
#include "Graph.h"
#include "Vertex.h"

using namespace std;


int main()
{
    Graph a;
    edge *p;
    a.load();

    /*for(int i = 0; i < a.numVer; i++)
    {
    cout << "A[" << i << "] =";
    p = a.V[i].first;
    while(p)
    {
      cout << "   " << p->vertex;
      p = p->next;
    }
    cout << endl;
    }*/


    cout << a.V[0].first->vertex;

}
