#include <iostream>
#include <windows.h>
#include "Interface.h"
#include "Graph.h"
#include "Vertex.h"

using namespace std;

template <typename T>
void Interface<T>::mainMenu(Graph<T> a)
{
    help=1;
    T b;
    edge<T> *p;
    //Vertex<T> *temp;
    //temp=a.getV();

    while(1)
    {
    help=1;
    cout<<"Graph and Bellman-Ford algorithm implementation:"<<endl;

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

        cout<<"1 - Bellman-Ford algorithm on loaded graph, write starting vertex"<<endl;
        cin>>b;




            a.BF(b);

            for(int j=0; j<a.getNumVer(); j++)
            {
                if(a.getCost()[j]<0)
                {
                    help=0;
                    break;
                }
            }


            if(help==1)
            {
            T *s=NULL;
            s = new T [a.getNumVer()];
            int i=0;

            for(int j=0; j<a.getNumVer(); j++)
            {
            cout<<a.getV()[j].getMyVertex()<<": ";
            p=a.getV()[j].getFirst();


            for(int k=j;k!=-1;k=a.getPredecessor()[k])
                s[i++]=a.getV()[k].getMyVertex();

            while(i)
                cout<<s[--i]<<" ";

                cout<<"$"<<a.getCost()[j]<<endl;
            }

            }
            else
            cout << "Negative cycle found!" << endl;


            help=1;

            a.initialize();


    }
}


template class Interface<int>;
template class Interface<double>;
template class Interface<string>;
template class Interface<char>;
