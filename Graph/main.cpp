#include <iostream>
#include "Graph.h"
#include "Vertex.h"
#include "Interface.h"

using namespace std;


int main()
{
    Interface<int> I;
    Graph<int> a;
    a.load();
    I.mainMenu(a);
}
