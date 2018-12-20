BF.exe : main.o Graph.o Vertex.o Interface.o Test.o
	g++ main.o Graph.o Vertex.o Interface.o Test.o -o BF.exe
main.o : main.cpp Graph.cpp Graph.h Vertex.cpp Vertex.h Interface.cpp Interface.h Test.cpp Test.h
	g++ -Wall -c main.cpp
Graph.o : Graph.cpp Graph.h
	g++ -Wall -c Graph.cpp
Vertex.o : Vertex.cpp Vertex.h
	g++ -Wall -c Vertex.cpp
Interface.o : Interface.cpp Interface.h
	g++ -Wall -c Interface.cpp
Test.o : Test.cpp Test.h
	g++ -Wall -c Test.cpp
clean :
	rm *.o BF.exe
