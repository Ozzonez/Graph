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



    a.BF('2');


    cout<<a.cost[0]<<endl;
    cout<<a.cost[1]<<endl;
    cout<<a.cost[2]<<endl;
    cout<<a.cost[3]<<endl;








}
