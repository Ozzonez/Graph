// Listy s¹siedztwa
// Data: 18.07.2013
// (C)2013 mgr Jerzy Wa³aszek
//---------------------------

#include <iostream>
#include <iomanip>

using namespace std;

// Typy dla dynamicznej tablicy list s¹siedztwa

struct slistEl
{
  slistEl * next;
  int v;
};

int main()
{
  int n,m,i,v1,v2;
  slistEl ** A;
  slistEl *p,*r;

  cin >> n >> m;         // Czytamy liczbê wierzcho³ków i krawêdzi

  A = new slistEl * [n]; // Tworzymy tablicê list s¹siedztwa

  // Tablicê wype³niamy pustymi listami

  for(i = 0; i < n; i++) A[i] = NULL;

  // Odczytujemy kolejne definicje krawêdzi

  for(i = 0; i < m; i++)
  {
    cin >> v1 >> v2;    // Wierzcho³ek startowy i koñcowy krawêdzi
    p = new slistEl;    // Tworzymy nowy element
    p->v = v2;          // Numerujemy go jako v2
    p->next = A[v1];    // Dodajemy go na pocz¹tek listy A[v1]
    A[v1] = p;
  }

  cout << endl;

  // Wypisujemy zawartoœæ tablicy list s¹siedztwa

  for(i = 0; i < n; i++)
  {
    cout << "A[" << i << "] =";
    p = A[i];
    while(p)
    {
      cout << setw(3) << p->v;
      p = p->next;
    }
    cout << endl;
  }

  // Usuwamy tablicê list s¹siedztwa

  for(i = 0; i < n; i++)
  {
    p = A[i];
    while(p)
    {
      r = p;
      p = p->next;
      delete r;
    }
  }
  delete [] A;

  cout << endl;

  return 0;
}
