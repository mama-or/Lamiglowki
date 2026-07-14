#include <memory>
#include "plansze/plansza.h"
#include "plansze/planszaProstokatna.h"
#include "plansze/planszaFigury.h"
#include "rozwiazania/rozwiazanie.h"
#include "rozwiazania/rozwiazanieProstokatne.h"
#include "rozwiazania/rozwiazaniePermutacje.h"
#include "rozwiazania/rozwiazaniePetla.h"
#include "ograniczenia/ograniczenie.h"
#include "znajdzTrzy.h"

ZnajdzTrzy::ZnajdzTrzy()
{
	plansza = std::make_unique<PlanszaFigury>(); 
}

std::unique_ptr<Rozwiazanie> ZnajdzTrzy::pierwszeRozwiazanie() const
{
    PlanszaFigury *pzn = (dynamic_cast<PlanszaFigury *> (plansza.get()));
    int ileFigur = pzn->getIleFigur();

	std::unique_ptr<RozwiazaniePermutacje> rozwiazanie = std::make_unique<RozwiazaniePermutacje>(ileFigur);

    rozwiazanie->wstaw(0, 0, 0);
    
    for(int i=1; i<ileFigur; i++)
        rozwiazanie->wstaw(i, 0, -1);
    
    return rozwiazanie;
}

bool ZnajdzTrzy::pobierzLamiglowke(std::string nazwaPliku)
{
    return plansza->pobierzLamiglowke(nazwaPliku);
}


bool ZnajdzTrzy::czyFiguryPasuja(const int figura1, const int figura2, const int figura3) const
{
    PlanszaFigury *pzn = (dynamic_cast<PlanszaFigury *> (plansza.get()));
    
    if(pzn->getKsztalt(figura1)==pzn->getKsztalt(figura2) && pzn->getKsztalt(figura1) != pzn->getKsztalt(figura3)) return false;
    if(pzn->getKsztalt(figura1)==pzn->getKsztalt(figura3) && pzn->getKsztalt(figura1) != pzn->getKsztalt(figura2)) return false;
    if(pzn->getKsztalt(figura2)==pzn->getKsztalt(figura3) && pzn->getKsztalt(figura2) != pzn->getKsztalt(figura1)) return false;
    
    if(pzn->getKolorWnetrza(figura1)==pzn->getKolorWnetrza(figura2) && pzn->getKolorWnetrza(figura1) != pzn->getKolorWnetrza(figura3)) return false;
    if(pzn->getKolorWnetrza(figura1)==pzn->getKolorWnetrza(figura3) && pzn->getKolorWnetrza(figura1) != pzn->getKolorWnetrza(figura2)) return false;
    if(pzn->getKolorWnetrza(figura2)==pzn->getKolorWnetrza(figura3) && pzn->getKolorWnetrza(figura2) != pzn->getKolorWnetrza(figura1)) return false;

    if(pzn->getKolorRamki(figura1)==pzn->getKolorRamki(figura2) && pzn->getKolorRamki(figura1) != pzn->getKolorRamki(figura3)) return false;
    if(pzn->getKolorRamki(figura1)==pzn->getKolorRamki(figura3) && pzn->getKolorRamki(figura1) != pzn->getKolorRamki(figura2)) return false;
    if(pzn->getKolorRamki(figura2)==pzn->getKolorRamki(figura3) && pzn->getKolorRamki(figura2) != pzn->getKolorRamki(figura1)) return false;

    if(pzn->getWzorWnetrza(figura1)==pzn->getWzorWnetrza(figura2) && pzn->getWzorWnetrza(figura1) != pzn->getWzorWnetrza(figura3)) return false;
    if(pzn->getWzorWnetrza(figura1)==pzn->getWzorWnetrza(figura3) && pzn->getWzorWnetrza(figura1) != pzn->getWzorWnetrza(figura2)) return false;
    if(pzn->getWzorWnetrza(figura2)==pzn->getWzorWnetrza(figura3) && pzn->getWzorWnetrza(figura2) != pzn->getWzorWnetrza(figura1)) return false;

    return true;
}

bool ZnajdzTrzy::czyPelneRozwiazanie(Rozwiazanie * rozw) const
{
    RozwiazaniePermutacje *rzt = (dynamic_cast<RozwiazaniePermutacje *> (rozw));
    PlanszaFigury *pf = (dynamic_cast<PlanszaFigury *> (plansza.get()));
    for(int i=0; i<pf->getIleFigur(); i++)
    {
        if(i%3==2 && rzt->getNr(i)!=-1)
        {
            bool wynik = czyFiguryPasuja(rzt->getNr(i-2), rzt->getNr(i-1), rzt->getNr(i));
            if(wynik==false) return false;
        }
    }
    return true;
}


bool ZnajdzTrzy::czyNiepelneRozwiazanie(Rozwiazanie * rozw) const
{
    return czyPelneRozwiazanie(rozw);
}
