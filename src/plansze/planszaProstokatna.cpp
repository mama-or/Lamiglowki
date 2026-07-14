#ifndef PLANSZA_PROSTOKATNA_CPP
#define PLANSZA_PROSTOKATNA_CPP

#include <fstream>
#include <iostream>
#include <vector>
#include "planszaProstokatna.h"
using namespace std;


bool PlanszaProstokatna::pobierzLamiglowke(string nazwaPliku)
{
    ifstream plik(nazwaPliku);

    if (!plik.is_open()) {
        cout << "Nie udało się otworzyć pliku!" << endl;
        return false;
    }
    plik >> ileKolumn >> ileWierszy;
    
	plansza.resize(ileWierszy);
    for(int i = 0; i<ileWierszy; ++i) {
		plansza[i].resize(ileKolumn);
        for(int j = 0; j<ileKolumn; ++j)
            plik >> plansza[i][j];
	}

    plik.close();
    return true;
}

void PlanszaProstokatna::wyswietlPlansze()
{
    for(int i = 0; i<ileWierszy; ++i)
    {
        for(int j = 0; j<ileKolumn; ++j)
            cout << plansza[i][j];
        cout << endl;
    }
}

#endif