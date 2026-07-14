#ifndef ROZWIAZANIE_PETLA_CPP
#define ROZWIAZANIE_PETLA_CPP

#include <iostream>
#include <vector>
#include "rozwiazaniePetla.h"

using namespace std;

RozwiazaniePetla::RozwiazaniePetla( const int wierszy, const int kolumn )
{
	rozwiazanie.resize((ileWierszy+1) * (ileKolumn+1));
    
    ileKolumn = kolumn;
    ileWierszy = wierszy;
    dlugoscDrogi = 0;
    xStartowy = -1;
    yStartowy = -1;
}
void RozwiazaniePetla::wyswietlRozwiazanie() const
{
    int tablica[ileWierszy][ileKolumn];
    
    for(int i=0; i<ileWierszy; i++) 
        for(int j=0; j<ileKolumn; j++) 
            tablica[i][j] = 0;
    
    int x = xStartowy;
    int y = yStartowy;
    
    if(dlugoscDrogi>0) tablica[x][y] = 1;
    
    for(int i=0; i<dlugoscDrogi; i++)
    {
        if(rozwiazanie[i]=='d') y++;
        if(rozwiazanie[i]=='g') y--;
        if(rozwiazanie[i]=='p') x++;
        if(rozwiazanie[i]=='l') x--;
        tablica[x][y] = 1;
    }
    for(int i=0; i<ileWierszy; i++) 
    {
        for(int j=0; j<ileKolumn; j++) 
            cout << tablica[i][j] << " ";
        cout <<endl;
    }
}

bool RozwiazaniePetla::czyNiepelneRozwiazanie() const
{
    return true;
}
bool RozwiazaniePetla::czyRozwiazanie() const
{
    return true;
}
std::unique_ptr<Rozwiazanie> RozwiazaniePetla::kopiuj() const
{
	return std::make_unique<RozwiazaniePetla>(*this);
}
void RozwiazaniePetla::wstaw(const int wiersz, const int kolumna, const int liczba) //1 - prawo, 2-dol, 3-lewo, 4-gora, wiersz i kolumna sa pomijane
{
	(void)wiersz;
	(void)kolumna;
    dlugoscDrogi++;
    if(liczba==1)
        rozwiazanie[dlugoscDrogi] = 'p';
    else if(liczba==2)
        rozwiazanie[dlugoscDrogi] = 'd';
    else if(liczba==3)
        rozwiazanie[dlugoscDrogi] = 'l';
    else if(liczba==4)
        rozwiazanie[dlugoscDrogi] = 'g';

}
void RozwiazaniePetla::pustaPozycja(int &wiersz, int &kolumna) const // zarowno wiersz jak i kolumna sa pomijane
{
    wiersz = 0;
    kolumna = 0;
}

bool RozwiazaniePetla::czyPelna() const // czy pelna petla, na razie nie sprawdzam czy sie przecina
{
    int pion = 0;
    int poziom = 0;
    for(int i=0; i<dlugoscDrogi; i++)
    {
        if(rozwiazanie[i]=='d') pion++;
        if(rozwiazanie[i]=='g') pion--;
        if(rozwiazanie[i]=='p') poziom++;
        if(rozwiazanie[i]=='l') poziom--;
    }
    if(pion==0 && poziom==0) return true;
    return false;
}

//1 - prawo, 2-dol, 3-lewo, 4-gora, wiersz i kolumna sa pomijane
std::vector<int> RozwiazaniePetla::mozliweWartosci(const int wiersz, const int kolumna) const
{
	(void)wiersz;
	(void)kolumna;
	std::vector<int> vec;

	vec.reserve(4);
    if(dlugoscDrogi==0)
    {
        vec.push_back(1); // prawo
        vec.push_back(2); // dol
        vec.push_back(3); // lewo
        vec.push_back(4); // gora
    }
    else if(rozwiazanie[dlugoscDrogi-1]=='g') 
    {
        vec.push_back(1); // prawo
        vec.push_back(3); // lewo
        vec.push_back(4); // gora
    }
    else if(rozwiazanie[dlugoscDrogi-1]=='d') 
    {
        vec.push_back(1); // prawo
        vec.push_back(2); // dol
        vec.push_back(3); // lewo
    }
    else if(rozwiazanie[dlugoscDrogi-1]=='p') 
    {
        vec.push_back(1); // prawo
        vec.push_back(2); // dol
        vec.push_back(4); // gora
    }
    else if(rozwiazanie[dlugoscDrogi-1]=='l') 
    {
        vec.push_back(2); // dol
        vec.push_back(3); // lewo
        vec.push_back(4); // gora
    }
    
    return vec;
}

#endif