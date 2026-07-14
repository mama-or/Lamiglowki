#ifndef UNIKALNY_WIERSZ_CPP
#define UNIKALNY_WIERSZ_CPP

#include "../rozwiazania/rozwiazanie.h"
#include "../rozwiazania/rozwiazanieProstokatne.h"
#include "unikalnyWiersz.h"
 
UnikalnyWiersz::UnikalnyWiersz(int wiersz, int ileKolumn): nrWiersza(wiersz), ile(ileKolumn)
{
}

bool UnikalnyWiersz::czySpelnia(Rozwiazanie *rozw)
{
	RozwiazanieProstokatne *rp = (dynamic_cast<RozwiazanieProstokatne *> (rozw));
	int ileWystapien;
	for(int liczba=1; liczba<=ile; liczba++)
	{
		ileWystapien = 0;
		for(int i=0; i<ile; i++)
			if(rp->wartosc(nrWiersza, i)==liczba)
				ileWystapien++;
		if(ileWystapien>1) return false;
	}
	
	return true;
}


#endif