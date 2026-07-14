#ifndef UNIKALNY_PROSTOKAT_CPP
#define UNIKALNY_PROSTOKAT_CPP

#include "../rozwiazania/rozwiazanie.h"
#include "../rozwiazania/rozwiazanieProstokatne.h"
#include "unikalnyProstokat.h"
 
UnikalnyProstokat::UnikalnyProstokat(int odX, int odY, int doX, int doY, int ile)
{
	this->odX = odX;
	this->doX = doX;
	this->odY = odY;
	this->doY = doY;
	this->ile = ile;
}

bool UnikalnyProstokat::czySpelnia(Rozwiazanie *rozw)
{
	RozwiazanieProstokatne *rp = (dynamic_cast<RozwiazanieProstokatne *> (rozw));
	int ileWystapien;
	for(int liczba=1; liczba<=ile; liczba++)
	{
		ileWystapien = 0;
		for(int i=odX; i<doX; i++)
			for(int j=odY; j<doY; j++)
				if(rp->wartosc(j, i)==liczba)
					ileWystapien++;
		if(ileWystapien>1) return false;
	}
	return true;
}

#endif