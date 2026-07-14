#include <iostream>
#include "algorytm/algorytm.h"
#include "lamiglowki/lamiglowka.h"
#include "lamiglowki/sudoku.h"
#include "lamiglowki/znajdzTrzy.h"
#include "lamiglowki/otwartaZagroda.h"

using namespace std;

//Sudoku lamiglowka;
//string nazwaPliku = "plansze/sudoku.txt";

ZnajdzTrzy lamiglowka;
string nazwaPliku = "plansze/znajdz trzy.txt";


//string nazwaPliku = "otwarta zagroda.txt";

int main()
{
    if(!lamiglowka.pobierzLamiglowke(nazwaPliku)) return false;
    cout << "Plansza:"<<endl;
    lamiglowka.wyswietlPlansze();

    algorytm(lamiglowka);

    return 0;
}
