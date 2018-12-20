#include <iostream>
#include "Graph.h"
#include "Vertex.h"


using namespace std;


int main()
{

    Graph<char> a;
    edge<char> *p;
    a.load();

    for(int i = 0; i < a.numVer; i++)
    {
    cout << "Vertex number " << i << " =";
    p = a.V[i].first;
    while(p)
    {
      cout << "   " << p->vertex;
      p = p->next;
    }
    cout << endl;
    }



    a.BFCD('2');



    cout<<endl;





}
