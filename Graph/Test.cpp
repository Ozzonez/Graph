#include <iostream>
#include "Test.h"
#include "Graph.h"

using namespace std;

void Test::testing()
{
    good=1;
    Graph<int> gr1;
    gr1.testingArguments();
    gr1.BF(0);
    cout<<"Does BF algorithm works correctly?"<<endl;



    if(gr1.getCost()[0]!=0)
        good=0;
    if(gr1.getCost()[1] != 1)
        good=0;
    if(gr1.getCost()[2] != 1)
        good=0;
    if(gr1.getCost()[3] != 1)
        good=0;
    if(gr1.getCost()[4] != 4)
        good=0;

    if(good==0)
    {
        cout<<"FAIL"<<endl;
    }
    else if(good==1)
    {
        cout<<"TEST PASSED"<<endl;
    }
}
