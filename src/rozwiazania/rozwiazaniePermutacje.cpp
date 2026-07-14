#ifndef ROZWIAZANIE_PERMUTACJE_CPP
#define ROZWIAZANIE_PERMUTACJE_CPP

#include <iostream>
#include <vector>
#include "rozwiazaniePermutacje.h"

using namespace std;

RozwiazaniePermutacje::RozwiazaniePermutacje(const int ile): ileLiczb(ile)
{
	rozwiazanie.resize(ileLiczb);
}

std::unique_ptr<Rozwiazanie> RozwiazaniePermutacje::kopiuj() const
{
	return std::make_unique<RozwiazaniePermutacje>(*this);
}

void RozwiazaniePermutacje::wstaw(const int wiersz, const int kolumna, const int liczba) // kolumna jest pomijana
{
	(void)kolumna;
    rozwiazanie[wiersz] = liczba;
}

void RozwiazaniePermutacje::wyswietlRozwiazanie() const
{
    for(int i = 0; i<ileLiczb; ++i)
    {
        cout << rozwiazanie[i] << " ";
        if(i%3==2)
            cout << endl;
    }
}

bool RozwiazaniePermutacje::czyPelna() const
{
    for(int i = 0; i<ileLiczb; ++i)
        if(rozwiazanie[i] == -1) return false;
    return true;
}

void RozwiazaniePermutacje::pustaPozycja(int &wiersz, int &kolumna) const // kolumna jest pomijana
{
    for(int i = 0; i<ileLiczb; ++i)
        if(rozwiazanie[i] == -1)
        {
            wiersz = i;
            kolumna = -1;
            return;
        }
}

bool RozwiazaniePermutacje::czyRozlaczneLiczby() const
{
    int ile;
    for(int liczba=0; liczba<ileLiczb; liczba++)
    {
        ile=0;
        for(int i=0; i<ileLiczb; i++)
            if(rozwiazanie[i]==liczba) ile++;
        if(ile>1) return false;
    }
    return true;
}
bool RozwiazaniePermutacje::czyRozwiazanie() const
{
    return czyRozlaczneLiczby(); 
}

bool RozwiazaniePermutacje::czyNiepelneRozwiazanie() const
{
    return czyRozwiazanie();
}

int RozwiazaniePermutacje::najmniejszaWolna() const
{
    int ile;
    for(int liczba=0; liczba<ileLiczb; liczba++)
    {
        ile=0;
        for(int i=0; i<ileLiczb; i++)
            if(rozwiazanie[i]==liczba) ile++;
        if(ile==0) return liczba;
    }
    return -1;
}
/*
list<int> RozwiazaniePermutacje::mozliweWartosci(const int wiersz, const int kolumna) const
{
    list<int> lista;
    if(wiersz%3==0)
        lista.push_back(najmniejszaWolna());
    else 
        for(int i=rozwiazanie[wiersz-1]+1; i<=17; i++)
            lista.push_back(i);
    return lista;
}
*/
std::vector<int> RozwiazaniePermutacje::mozliweWartosci(const int wiersz, const int kolumna) const
{
	(void)wiersz;
	(void)kolumna;
	std::vector<int> vec;

	vec.reserve(ileLiczb);
    for(int i=0; i<ileLiczb; i++)
        vec.push_back(i);
    return vec;
}


#endif