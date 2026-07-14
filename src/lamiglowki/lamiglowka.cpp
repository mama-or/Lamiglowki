#ifndef LAMIGLOWKA_CPP
#define LAMIGLOWKA_CPP

#include "../plansze/plansza.h"
#include "../rozwiazania/rozwiazanie.h"
#include "../ograniczenia/ograniczenie.h"
#include "lamiglowka.h"

bool Lamiglowka::pobierzLamiglowke(std::string nazwaPliku)
{
    return plansza->pobierzLamiglowke(nazwaPliku);
}
void Lamiglowka::wyswietlPlansze()
{
    plansza->wyswietlPlansze();
}


#endif
