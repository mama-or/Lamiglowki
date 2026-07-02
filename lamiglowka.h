#ifndef LAMIGLOWKA_H
#define LAMIGLOWKA_H

#include "plansza.h"
#include "rozwiazanie.h"


class Lamiglowka
{
    public:
        Lamiglowka () {};
        ~Lamiglowka() {delete plansza;};
        
        bool pobierzLamiglowke(string nazwaPliku);
        void wyswietlPlansze();
        
        virtual Rozwiazanie* pierwszeRozwiazanie() const = 0;
        virtual bool czyPelneRozwiazanie(Rozwiazanie * rozw) const = 0;
        virtual bool czyNiepelneRozwiazanie(Rozwiazanie * rozw) const = 0;
    
    protected:
        Plansza *plansza;
        
};

class Sudoku: public Lamiglowka
{
    public:
        Sudoku(){ plansza = new PlanszaProstokatna; };
        virtual Rozwiazanie* pierwszeRozwiazanie() const;
        virtual bool czyPelneRozwiazanie(Rozwiazanie * rozw) const;
        virtual bool czyNiepelneRozwiazanie(Rozwiazanie * rozw) const;

};

class ZnajdzTrzy: public Lamiglowka
{
    public:
        ZnajdzTrzy(){ plansza = new PlanszaFigury; };
        virtual Rozwiazanie* pierwszeRozwiazanie() const;
        virtual bool czyPelneRozwiazanie(Rozwiazanie * rozw) const;
        virtual bool czyNiepelneRozwiazanie(Rozwiazanie * rozw) const;
    private:
        bool czyFiguryPasuja(const int figura1, const int figura2, const int figura3) const;
};

class OtwartaZagroda: public Lamiglowka
{
    public:
        OtwartaZagroda(){ plansza = new PlanszaProstokatna; };
        virtual Rozwiazanie* pierwszeRozwiazanie() const;
        virtual bool czyPelneRozwiazanie(Rozwiazanie * rozw) const;
        virtual bool czyNiepelneRozwiazanie(Rozwiazanie * rozw) const;
};


//////////////////////////////////////////////////////

bool Lamiglowka::pobierzLamiglowke(string nazwaPliku)
{
    return plansza->pobierzLamiglowke(nazwaPliku);
}
void Lamiglowka::wyswietlPlansze()
{
    plansza->wyswietlPlansze();
}

////////////////////////////////////////////////////////////

Rozwiazanie* Sudoku::pierwszeRozwiazanie() const
{
    PlanszaProstokatna *pp = (dynamic_cast<PlanszaProstokatna *> (plansza));
    int ileKolumn = pp->getIleKolumn();
    int ileWierszy = pp->getIleWierszy();
    
    RozwiazanieSudoku* rozwiazanie = new RozwiazanieSudoku(ileWierszy, ileKolumn);
    
    for(int i = 0; i<ileWierszy; ++i)
        for(int j = 0; j<ileKolumn; ++j)
            rozwiazanie->wstaw(i, j, pp->getPlansza(i, j));

    return rozwiazanie;
}

bool Sudoku::czyPelneRozwiazanie(Rozwiazanie * rozw) const
{
	(void)rozw;
    return true;
}

bool Sudoku::czyNiepelneRozwiazanie(Rozwiazanie * rozw) const
{
	(void)rozw;
    return true;
}


////////////////////////////////////////////////////////////

Rozwiazanie* ZnajdzTrzy::pierwszeRozwiazanie() const
{
    PlanszaFigury *pzn = (dynamic_cast<PlanszaFigury *> (plansza));
    int ileFigur = pzn->getIleFigur();

    RozwiazaniePermutacje* rozwiazanie = new RozwiazaniePermutacje(ileFigur);

    rozwiazanie->wstaw(0, 0, 0);
    
    for(int i=1; i<ileFigur; i++)
        rozwiazanie->wstaw(i, 0, -1);
    
    return rozwiazanie;
}

bool ZnajdzTrzy::czyFiguryPasuja(const int figura1, const int figura2, const int figura3) const
{
    PlanszaFigury *pzn = (dynamic_cast<PlanszaFigury *> (plansza));
    
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
    PlanszaFigury *pf = (dynamic_cast<PlanszaFigury *> (plansza));
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


#endif
