// Listy s�siedztwa
// Data: 18.07.2013
// (C)2013 mgr Jerzy Wa�aszek
//---------------------------

#include <iostream>
#include <iomanip>

using namespace std;

// Typy dla dynamicznej tablicy list s�siedztwa

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

  cin >> n >> m;         // Czytamy liczb� wierzcho�k�w i kraw�dzi

  A = new slistEl * [n]; // Tworzymy tablic� list s�siedztwa

  // Tablic� wype�niamy pustymi listami

  for(i = 0; i < n; i++) A[i] = NULL;

  // Odczytujemy kolejne definicje kraw�dzi

  for(i = 0; i < m; i++)
  {
    cin >> v1 >> v2;    // Wierzcho�ek startowy i ko�cowy kraw�dzi
    p = new slistEl;    // Tworzymy nowy element
    p->v = v2;          // Numerujemy go jako v2
    p->next = A[v1];    // Dodajemy go na pocz�tek listy A[v1]
    A[v1] = p;
  }

  cout << endl;

  // Wypisujemy zawarto�� tablicy list s�siedztwa

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

  // Usuwamy tablic� list s�siedztwa

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
