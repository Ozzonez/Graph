#include <iostream>
#include <windows.h>
#include "Interface.h"
#include "Graph.h"
#include "Vertex.h"
#include "Test.h"

using namespace std;


void Interface::mainMenu()
{
    help=1;
    edge<int> *p;
    Graph<int> a;
    a.load();
    int b, v;
    Test t1;

    while(1)
    {
    help=1;
    cout<<"Graph and Bellman-Ford algorithm implementation:"<<endl;
    cout<<"1 - Test"<<endl;
    cout<<"2 - Bellman-Ford algorithm"<<endl;
    cin>>v;
    system("cls");
    if(v==2)
    {
    for(int i = 0; i < a.getNumVer(); i++)
    {
    cout << "Vertex number " << a.getV()[i].getMyVertex() << " =";
    p = a.getV()[i].getFirst();

    while(p)
    {
      cout << "   " << p->vertex;
      p = p->next;
    }
    cout << endl;
    }

        cout<<"Bellman-Ford algorithm on loaded graph, write starting vertex"<<endl;
        cin>>b;

        a.BF(b);
        a.Show(b);
        a.initialize();
    }
    if(v==1)
    {
        system("cls");
        t1.testing();
    }

    }
}


