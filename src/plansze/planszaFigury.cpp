#ifndef PLANSZA_FIGURY_CPP
#define PLANSZA_FIGURY_CPP

#include <fstream>
#include <iostream>
#include <vector>
#include "planszaFigury.h"

using namespace std;

bool PlanszaFigury::pobierzLamiglowke(string nazwaPliku)
{
    ifstream plik(nazwaPliku);

    if (!plik.is_open()) {
        cout << "Nie udało się otworzyć pliku!" << endl;
        return false;
    }
    plik >> ileFigur;
    
	ksztalty.resize(ileFigur);
	koloryWnetrza.resize(ileFigur);
	koloryRamki.resize(ileFigur);
	wzoryWnetrza.resize(ileFigur);

    for(int i = 0; i<ileFigur; ++i)
        plik >> ksztalty[i] >> koloryWnetrza[i] >> koloryRamki[i] >> wzoryWnetrza[i];
    plik.close();
    return true;
}

void PlanszaFigury::wyswietlPlansze()
{
    for(int i = 0; i<ileFigur; ++i)
        cout << ksztalty[i] << koloryWnetrza[i] << koloryRamki[i] << wzoryWnetrza[i] << endl;
}

#endif