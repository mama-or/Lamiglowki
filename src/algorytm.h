#ifndef ALGORYTM_H
#define ALGORYTM_H

#include <iostream>
#include <stack>
#include <memory>
#include "lamiglowka.h"

using namespace std;

void algorytm(Lamiglowka &lamiglowka)
{
    stack<std::unique_ptr<Rozwiazanie> > stos;
	std::unique_ptr<Rozwiazanie> r = lamiglowka.pierwszeRozwiazanie();
    
    stos.push(std::move(r));

    while(!stos.empty())
    {
        
		std::unique_ptr<Rozwiazanie> r = std::move(stos.top());
        stos.pop();

        if(r->czyNiepelneRozwiazanie() && lamiglowka.czyNiepelneRozwiazanie(r.get()))
        {
            if(r->czyPelna())
            {
                if(r->czyRozwiazanie() && lamiglowka.czyPelneRozwiazanie(r.get()))
                {
                    cout << "Rozwiazanie: " <<endl;
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
