#ifndef ROZWIAZANIE_PROSTOKATNE_CPP
#define ROZWIAZANIE_PROSTOKATNE_CPP

#include <iostream>
#include <vector>
#include "rozwiazanieProstokatne.h"

using namespace std;

RozwiazanieProstokatne::RozwiazanieProstokatne( const int wierszy, const int kolumn ): ileKolumn (kolumn), ileWierszy(wierszy)
{
    rozwiazanie.resize(ileWierszy);
    for(int i=0; i<ileWierszy; i++)
        rozwiazanie[i].resize(ileKolumn);
}

std::unique_ptr<Rozwiazanie> RozwiazanieProstokatne::kopiuj() const
{
	return std::make_unique<RozwiazanieProstokatne>(*this);
}

void RozwiazanieProstokatne::wstaw(const int wiersz, const int kolumna, const int liczba)
{
    rozwiazanie[wiersz][kolumna] = liczba;
}

void RozwiazanieProstokatne::wyswietlRozwiazanie() const
{
    for(int i = 0; i<ileWierszy; ++i)
    {
        for(int j = 0; j<ileKolumn; ++j)
            cout << rozwiazanie[i][j];
        cout << endl;
    }
}

bool RozwiazanieProstokatne::czyPelna() const
{
    for(int i = 0; i<ileWierszy; ++i)
        for(int j = 0; j<ileKolumn; ++j)
            if(rozwiazanie[i][j] == 0) return false;
    return true;
}

void RozwiazanieProstokatne::pustaPozycja(int &wiersz, int &kolumna) const
{
    for(int i = 0; i<ileWierszy; ++i)
        for(int j = 0; j<ileKolumn; ++j)
            if(rozwiazanie[i][j] == 0)
            {
                wiersz = i;
                kolumna = j;
                return;
            }
}
bool RozwiazanieProstokatne::czyRozlaczneKolumny() const
{
    for(int i = 0; i<ileWierszy; ++i)
    {
        for(int liczba = 1; liczba<=9; ++liczba)
        {
            int ile=0;
            for(int j = 0; j<ileKolumn; ++j)
                if(rozwiazanie[i][j] == liczba)
                    ++ile;
            if(ile>1) return false;
        }
    }
    return true;
}

bool RozwiazanieProstokatne::czyRozlaczneWiersze() const
{
    for(int j = 0; j<ileWierszy; ++j)
    {
        for(int liczba = 1; liczba<=9; ++liczba)
        {
            int ile=0;
            for(int i = 0; i<ileKolumn; ++i)
                if(rozwiazanie[i][j] == liczba)
                    ++ile;
            if(ile>1) return false;
        }
    }
    return true;

}

bool RozwiazanieProstokatne::czyRozlaczneKwadraty() const
{
    for(int a = 0; a<3; ++a)
        for(int b = 0; b<3; ++b)
        {
            for(int liczba = 1; liczba<=9; ++liczba)
            {
                int ile=0;
                for(int c = 0; c<3; ++c)
                    for(int d = 0; d<3; ++d)
                        if(rozwiazanie[3*a+b][3*c+d] == liczba)
                            ++ile;
                if(ile>1) return false;
            }
        }
    return true;
}

bool RozwiazanieProstokatne::czyRozwiazanie() const
{
    return czyRozlaczneKolumny() && czyRozlaczneWiersze() && czyRozlaczneKwadraty();
}

bool RozwiazanieProstokatne::czyNiepelneRozwiazanie() const
{
    return czyRozwiazanie();
}

std::vector<int> RozwiazanieProstokatne::mozliweWartosci(const int wiersz, const int kolumna) const
{
	(void)wiersz;
	(void)kolumna;
	std::vector<int> vec;

	vec.reserve(9);
    for (int i=1;i<=9;i++)
        vec.push_back(i);
    return vec;
}

int RozwiazanieProstokatne::wartosc(int wiersz, int kolumna)
{
	return rozwiazanie[wiersz][kolumna];
}


#endif