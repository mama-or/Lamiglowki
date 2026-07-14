#ifndef SUDOKU_CPP
#define SUDOKU_CPP

#include <memory>
#include "../plansze/planszaProstokatna.h"
#include "../rozwiazania/rozwiazanieProstokatne.h"
#include "../ograniczenia/ograniczenie.h"
#include "../ograniczenia/unikalnyWiersz.h"
#include "../ograniczenia/unikalnaKolumna.h"
#include "../ograniczenia/unikalnyProstokat.h"
#include "sudoku.h"

using namespace std;


Sudoku::Sudoku()
{ 
	plansza = std::make_unique<PlanszaProstokatna>(); 
};

bool Sudoku::pobierzLamiglowke(string nazwaPliku)
{
    bool wynik =  plansza->pobierzLamiglowke(nazwaPliku);
	
	PlanszaProstokatna *pp = (static_cast<PlanszaProstokatna *> (plansza.get()));
	int ileWierszy = pp->getIleWierszy();
	int ileKolumn = pp->getIleKolumn();
	
	std::unique_ptr<Ograniczenie> ogr;
	ograniczenia.reserve(3*ileWierszy);
	
	for(int i=0; i<ileWierszy; i++)
	{
		std::unique_ptr<UnikalnyWiersz> ogr = std::make_unique<UnikalnyWiersz>(i, ileKolumn); 
		ograniczenia.push_back(std::move(ogr));
	}
	for(int j=0; j<ileKolumn; j++)	
	{
		std::unique_ptr<UnikalnaKolumna> ogr = std::make_unique<UnikalnaKolumna>(j, ileWierszy); 
		ograniczenia.push_back(std::move(ogr));
	}
	for(int i=0; i<3; i++)	
		for(int j=0; j<3; j++)	
		{
			std::unique_ptr<UnikalnyProstokat> ogr = std::make_unique<UnikalnyProstokat>(3*i, 3*j, 3*i+2, 3*j+2, ileWierszy); 
			
			ograniczenia.push_back(std::move(ogr));
		}

	return wynik;
}


std::unique_ptr<Rozwiazanie> Sudoku::pierwszeRozwiazanie() const
{
    PlanszaProstokatna *pp = (dynamic_cast<PlanszaProstokatna *> (plansza.get()));
    int ileKolumn = pp->getIleKolumn();
    int ileWierszy = pp->getIleWierszy();
    
	std::unique_ptr<RozwiazanieProstokatne> rozwiazanie = std::make_unique<RozwiazanieProstokatne>(ileWierszy, ileKolumn);
    
    for(int i = 0; i<ileWierszy; ++i)
        for(int j = 0; j<ileKolumn; ++j)
            rozwiazanie->wstaw(i, j, pp->getPlansza(i, j));

    return rozwiazanie;
}

bool Sudoku::czyPelneRozwiazanie(Rozwiazanie * rozw) const
{	
	return (rozw->czyPelna() && rozw->czyNiepelneRozwiazanie());}

bool Sudoku::czyNiepelneRozwiazanie(Rozwiazanie * rozw) const
{
	return rozw->czyNiepelneRozwiazanie();
}


#endif