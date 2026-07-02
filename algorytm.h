#ifndef ALGORYTM_H
#define ALGORYTM_H

#include <iostream>
#include <stack>
#include "lamiglowka.h"

using namespace std;

void algorytm(Lamiglowka &lamiglowka)
{
    stack<Rozwiazanie*> stos;
    Rozwiazanie *r = lamiglowka.pierwszeRozwiazanie();
    
    stos.push(r);

    while(!stos.empty())
    {
        
        Rozwiazanie *r = stos.top();
        stos.pop();

        if(r->czyNiepelneRozwiazanie() && lamiglowka.czyNiepelneRozwiazanie(r))
        {
            if(r->czyPelna())
            {
                if(r->czyRozwiazanie() && lamiglowka.czyPelneRozwiazanie(r))
                {
                    cout << "Rozwiazanie: " <<endl;
                    r->wyswietlRozwiazanie();
                    
                    while(!stos.empty())
                    {
                        r = stos.top();
                        stos.pop();
                        delete r;
                    }
                    return;
                }
            }
            else
            {
                int kolumna, wiersz;
                r->pustaPozycja(wiersz, kolumna);
                list<int> wartosci = r->mozliweWartosci(wiersz, kolumna);
                
                for (int liczba: wartosci) 
                {
                    Rozwiazanie *r2 = r->kopiuj();
                    r2->wstaw(wiersz, kolumna, liczba);
                    stos.push(r2);
                }
                
            }
            delete r;
        }
    }
}

#endif