// Algorytm Bellmana-Forda
// Data   : 13.04.2014
// (C)2014 mgr Jerzy Wa�aszek
//---------------------------

#include <iostream>

using namespace std;

const int MAXINT = 2147483647;    // Najwi�ksza liczba ca�kowita

// Typy danych
struct slistEl
{
  slistEl * next;
  int v,w;
};

// Zmienne globalne
int m,n;                          // Liczba kraw�dzi i wierzcho�k�w w grafie
slistEl ** A;                     // Tablica dynamiczna list s�siedztwa
long long * d;                    // Tablica koszt�w doj�cia
int * p;                          // Tablica poprzednik�w

// Funkcja wyznacza najkr�tsze �cie�ki
// v - wierzcho�ek startowy
// Wyj�cie:
// true  - wyniki w d i p
// false - graf zawiera ujemny cykl
//------------------------------------
bool BF(int v)
{
  int i,x;
  bool test;
  slistEl * pv;

  d[v] = 0;                       // Zerujemy koszt doj�cia do v
  for(i = 1; i < n; i++)          // P�tla relaksacji
  {
    test = true;                  // Oznacza, �e algorytm nie wprowadzi� zmian do d i p
    for(x = 0; x < n; x++)        // Przechodzimy przez kolejne wierzcho�ki grafu
      for(pv = A[x]; pv; pv = pv->next) // Przegl�damy list� s�siad�w wierzcho�ka x
        if(d[pv->v] > d[x] + pv->w) // Sprawdzamy warunek relaksacji
        {
          test = false;           // Jest zmiana w d i p
          d[pv->v] = d[x] + pv->w; // Relaksujemy kraw�d� z x do jego s�siada
          p[pv->v] = x;           // Poprzednikiem s�siada b�dzie x
        }
    if(test) return true;         // Je�li nie by�o zmian, to ko�czymy
  }

  // Sprawdzamy istnienie ujemnego cyklu

  for(x = 0; x < n; x++)
    for(pv = A[x];pv;pv = pv->next)
      if(d[pv->v] > d[x] + pv->w) return false; // ujemny cykl!!

  return true;
}

// **********************
// *** PROGRAM G��WNY ***
// **********************
int main()
{
  int i,v,x,y,w,sptr,*S;
  slistEl *rv,*pv;

  cin >> v >> n >> m;             // Wierzcho�ek startowy, liczba wierzcho�k�w i kraw�dzi

  A = new slistEl * [n];          // Tworzymy tablic� list s�siedztwa
  d = new long long [n];          // Tworzymy tablic� koszt�w doj�cia
  p = new int [n];                // Tworzymy tablice poprzednik�w
  for(i = 0; i < n; i++)          // Inicjujemy struktury danych
  {
    d[i] = MAXINT;
    p[i] = -1;
    A[i] = NULL;
  }

  for(i = 0; i < m; i++)
  {
    cin >> x >> y >> w;           // Czytamy wierzcho�ki kraw�dzi oraz jej wag�
    pv = new slistEl;             // Tworzymy element listy
    pv->v = y;                    // Inicjujemy go
    pv->w = w;
    pv->next = A[x];              // Dodajemy go na pocz�tek listy s�siad�w wierzcho�ka x
    A[x] = pv;
  }

  cout << endl;

  // Wyznaczamy najkr�tsze �cie�ki algorytmem Bellmana-Forda

  if(BF(v))
  {
    S = new int [n];              // Tworzymy prosty stos
    sptr = 0;

    for(i = 0; i < n; i++)
    {
      cout << i << ": ";
      for(x = i;x != -1;x = p[x]) // Wierzcho�ki �cie�ki umieszczamy na stosie
        S[sptr++] = x;            // w kolejno�ci od ostatniego do pierwszego

      while(sptr)                 // Wierzcho�ki ze stosu drukujemy
        cout << S[--sptr] << " "; // w kolejno�ci od pierwszego do ostatniego

      cout << "$" << d[i] << endl; // Na ko�cu wy�wietlamy koszt
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
