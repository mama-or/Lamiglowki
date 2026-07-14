#ifndef UNIKALNA_KOLUMNA_CPP
#define UNIKALNA_KOLUMNA_CPP

#include "../rozwiazania/rozwiazanie.h"
#include "../rozwiazania/rozwiazanieProstokatne.h"
#include "unikalnaKolumna.h"
 
UnikalnaKolumna::UnikalnaKolumna(int kolumna, int ileKolumn): nrKolumny(kolumna), ile(ileKolumn)
{
}

bool UnikalnaKolumna::czySpelnia(Rozwiazanie *rozw)
{
	RozwiazanieProstokatne *rp = (dynamic_cast<RozwiazanieProstokatne *> (rozw));
	int ileWystapien;
	for(int liczba=1; liczba<=ile; liczba++)
	{
		ileWystapien = 0;
		for(int i=0; i<ile; i++)
			if(rp->wartosc(i, nrKolumny)==liczba)
				ileWystapien++;
		if(ileWystapien>1) return false;
	}
	
	return true;
}

#endif