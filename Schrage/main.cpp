#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <queue>


using namespace std;

struct Pojedyncze_zadanie
{
public:
     int r,p,q;
     int nr_zad;
};

struct ZbiorN
{
     bool operator()(Pojedyncze_zadanie& a, Pojedyncze_zadanie& b)
     {
          return a.r > b.r;
     }
};

struct ZbiorG
{
     bool operator()(Pojedyncze_zadanie& a, Pojedyncze_zadanie& b)
     {
          return a.q < b.q;
     }
};

priority_queue<Pojedyncze_zadanie,vector<Pojedyncze_zadanie>,ZbiorN> N;
priority_queue<Pojedyncze_zadanie,vector<Pojedyncze_zadanie>,ZbiorG> G;


istream& operator >> (istream& wejscie, Pojedyncze_zadanie& zadanie)
{
     wejscie >> zadanie.r >> zadanie.p >> zadanie.q;
     return wejscie;
}

ostream& operator << (ostream& wyjscie, Pojedyncze_zadanie& zadanie)
{
     cout << zadanie.r << " " << zadanie.p << " " << zadanie.q << endl;
     return wyjscie;
}

Pojedyncze_zadanie tab[100];
Pojedyncze_zadanie nr_zadania[100];
int n;
int liczba_zadan;
int Cmax;
int t;


void Wczytaj()
{

ifstream plik;
plik.open( "SCHRAGE2.DAT", ios::in);
plik >> n;
liczba_zadan=n+1;
 for(int i=1;i<n+1;i++)
 {
      plik >> tab[i];
      cout << tab[i];
 }
 plik.close();
cout << endl;
}


void Sortuj()
{
for( int i = 0; i < liczba_zadan; i++ )
    {
        for(int j=0; j<liczba_zadan-1; j++)
        {
            if( tab[j].r > tab[j+1].r )
                 swap( tab[j], tab[j+1]);
        }
    }
}

void Wyswietl()
{
     for(int i=1;i<liczba_zadan;i++)
          cout << tab[i];
}
/*
void Schrage()
{
*
 int n=liczba_zadan;
 int k=0;
 t=tab[0].r;

 while(!(N.empty) || !(G.empty) )
 {
      while (!(N.empty) && N.top() <= t)

 }

}
*/


int main()
{
 Wczytaj();
 Sortuj();
 Wyswietl();


 return 0;

}
