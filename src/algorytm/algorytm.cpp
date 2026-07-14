#ifndef ALGORYTM_CPP
#define ALGORYTM_CPP

#include <iostream>
#include <stack>
#include <memory>
#include "../lamiglowki/lamiglowka.h"
#include "algorytm.h"

void algorytm(Lamiglowka &lamiglowka)
{
    std::stack<std::unique_ptr<Rozwiazanie> > stos;
	std::unique_ptr<Rozwiazanie> r = lamiglowka.pierwszeRozwiazanie();
    
    stos.push(std::move(r));

    while(!stos.empty())
    {
        
		std::unique_ptr<Rozwiazanie> r = std::move(stos.top());
        stos.pop();

		if(lamiglowka.czyNiepelneRozwiazanie(r.get()) && lamiglowka.czyNiepelneRozwiazanie(r.get()))
//        if(r->czyNiepelneRozwiazanie() && lamiglowka.czyNiepelneRozwiazanie(r.get()))
        {
            if(r->czyPelna())
            {
                if(r->czyRozwiazanie() && lamiglowka.czyPelneRozwiazanie(r.get()))
                {
                    std::cout << "Rozwiazanie: " <<std::endl;
                    r->wyswietlRozwiazanie();
                    
                    while(!stos.empty())
                    {
                        r = std::move(stos.top());
                        stos.pop();
                    }
                    return;
                }
            }
            else
            {
                int kolumna, wiersz;
                r->pustaPozycja(wiersz, kolumna);
				std::vector<int> wartosci = r->mozliweWartosci(wiersz, kolumna);
                
                for (int liczba: wartosci) 
                {
					std::unique_ptr<Rozwiazanie> r2 = r->kopiuj();
                    r2->wstaw(wiersz, kolumna, liczba);
                    stos.push(std::move(r2));
                }
                
            }
        }
    }
}

#endif
