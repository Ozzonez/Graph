// Algorytm Bellmana-Forda
// Data   : 13.04.2014
// (C)2014 mgr Jerzy Wa³aszek
//---------------------------

#include <iostream>

using namespace std;

const int MAXINT = 2147483647;    // Najwiêksza liczba ca³kowita

// Typy danych
struct slistEl
{
  slistEl * next;
  int v,w;
};

// Zmienne globalne
int m,n;                          // Liczba krawêdzi i wierzcho³ków w grafie
slistEl ** A;                     // Tablica dynamiczna list s¹siedztwa
long long * d;                    // Tablica kosztów dojœcia
int * p;                          // Tablica poprzedników

// Funkcja wyznacza najkrótsze œcie¿ki
// v - wierzcho³ek startowy
// Wyjœcie:
// true  - wyniki w d i p
// false - graf zawiera ujemny cykl
//------------------------------------
bool BF(int v)
{
  int i,x;
  bool test;
  slistEl * pv;

  d[v] = 0;                       // Zerujemy koszt dojœcia do v
  for(i = 1; i < n; i++)          // Pêtla relaksacji
  {
    test = true;                  // Oznacza, ¿e algorytm nie wprowadzi³ zmian do d i p
    for(x = 0; x < n; x++)        // Przechodzimy przez kolejne wierzcho³ki grafu
      for(pv = A[x]; pv; pv = pv->next) // Przegl¹damy listê s¹siadów wierzcho³ka x
        if(d[pv->v] > d[x] + pv->w) // Sprawdzamy warunek relaksacji
        {
          test = false;           // Jest zmiana w d i p
          d[pv->v] = d[x] + pv->w; // Relaksujemy krawêdŸ z x do jego s¹siada
          p[pv->v] = x;           // Poprzednikiem s¹siada bêdzie x
        }
    if(test) return true;         // Jeœli nie by³o zmian, to koñczymy
  }

  // Sprawdzamy istnienie ujemnego cyklu

  for(x = 0; x < n; x++)
    for(pv = A[x];pv;pv = pv->next)
      if(d[pv->v] > d[x] + pv->w) return false; // ujemny cykl!!

  return true;
}

// **********************
// *** PROGRAM G£ÓWNY ***
// **********************
int main()
{
  int i,v,x,y,w,sptr,*S;
  slistEl *rv,*pv;

  cin >> v >> n >> m;             // Wierzcho³ek startowy, liczba wierzcho³ków i krawêdzi

  A = new slistEl * [n];          // Tworzymy tablicê list s¹siedztwa
  d = new long long [n];          // Tworzymy tablicê kosztów dojœcia
  p = new int [n];                // Tworzymy tablice poprzedników
  for(i = 0; i < n; i++)          // Inicjujemy struktury danych
  {
    d[i] = MAXINT;
    p[i] = -1;
    A[i] = NULL;
  }

  for(i = 0; i < m; i++)
  {
    cin >> x >> y >> w;           // Czytamy wierzcho³ki krawêdzi oraz jej wagê
    pv = new slistEl;             // Tworzymy element listy
    pv->v = y;                    // Inicjujemy go
    pv->w = w;
    pv->next = A[x];              // Dodajemy go na pocz¹tek listy s¹siadów wierzcho³ka x
    A[x] = pv;
  }

  cout << endl;

  // Wyznaczamy najkrótsze œcie¿ki algorytmem Bellmana-Forda

  if(BF(v))
  {
    S = new int [n];              // Tworzymy prosty stos
    sptr = 0;

    for(i = 0; i < n; i++)
    {
      cout << i << ": ";
      for(x = i;x != -1;x = p[x]) // Wierzcho³ki œcie¿ki umieszczamy na stosie
        S[sptr++] = x;            // w kolejnoœci od ostatniego do pierwszego

      while(sptr)                 // Wierzcho³ki ze stosu drukujemy
        cout << S[--sptr] << " "; // w kolejnoœci od pierwszego do ostatniego

      cout << "$" << d[i] << endl; // Na koñcu wyœwietlamy koszt
    }
    delete [] S;                  // Usuwamy stos
  }
  else cout << "Negative Cycle found!" << endl;

  // Usuwamy struktury dynamiczne

  for(i = 0; i < n; i++)
  {
    pv = A[i];
    while(pv)
    {
      rv = pv;
      pv = pv->next;
      delete rv;
    }
  }

  delete [] A;
  delete [] d;
  delete [] p;

  return 0;
}
