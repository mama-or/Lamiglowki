#ifndef ROZWIAZANIE_H
#define ROZWIAZANIE_H

#include <iostream>
#include <list>

using namespace std;

class Rozwiazanie
{
    public: 
        virtual void wyswietlRozwiazanie() const = 0;
        virtual Rozwiazanie* kopiuj() const = 0;
        virtual bool czyNiepelneRozwiazanie() const = 0;
        virtual bool czyRozwiazanie() const = 0;
        virtual void wstaw(const int wiersz, const int kolumna, const int liczba) = 0;
        virtual void pustaPozycja(int &wiersz, int &kolumna) const = 0;
        virtual bool czyPelna() const = 0;
        virtual list<int> mozliweWartosci(const int wiersz, const int kolumna) const = 0;
};

/////////////////////////////////////////////////////////

class RozwiazanieSudoku: public Rozwiazanie
{
    public:
        RozwiazanieSudoku( const RozwiazanieSudoku & rozw );
        RozwiazanieSudoku( const int wierszy, const int kolumn );
        RozwiazanieSudoku( ) {};
        ~RozwiazanieSudoku();
        
        virtual Rozwiazanie* kopiuj() const;
        
        virtual void wyswietlRozwiazanie() const;
        bool czyNiepelneRozwiazanie() const;
        virtual bool czyRozwiazanie() const;
        virtual void wstaw(const int wiersz, const int kolumna, const int liczba);
        virtual void pustaPozycja(int &wiersz, int &kolumna) const;
        virtual bool czyPelna() const;
        virtual list<int> mozliweWartosci(const int wiersz, const int kolumna) const;
    private:
        bool czyRozlaczneKolumny() const;
        bool czyRozlaczneWiersze() const;
        bool czyRozlaczneKwadraty() const;
    
        int **rozwiazanie;
        int ileKolumn, ileWierszy;
};

class RozwiazaniePetla: public Rozwiazanie
{
    public:
        RozwiazaniePetla( ) {};
        RozwiazaniePetla( const RozwiazaniePetla & rozw );
        RozwiazaniePetla( const int wierszy, const int kolumn );
        ~RozwiazaniePetla();
        
        virtual Rozwiazanie* kopiuj() const;
        
        virtual void wyswietlRozwiazanie() const;
        bool czyNiepelneRozwiazanie() const;
        virtual bool czyRozwiazanie() const;
        virtual void wstaw(const int wiersz, const int kolumna, const int liczba);
        virtual void pustaPozycja(int &wiersz, int &kolumna) const;
        virtual bool czyPelna() const;
        virtual list<int> mozliweWartosci(const int wiersz, const int kolumna) const;
    private:
        int xStartowy, yStartowy;
        char *rozwiazanie; // p - prawo, d - dol, l - lewo, g - gora
        int ileKolumn, ileWierszy;
        int dlugoscDrogi;
};

/////////////////////////////////////////////////////////

class RozwiazaniePermutacje: public Rozwiazanie
{
    public:
        RozwiazaniePermutacje( const RozwiazaniePermutacje & rozw );
        RozwiazaniePermutacje( ) {};
        RozwiazaniePermutacje(const int ile);
        ~RozwiazaniePermutacje();
        
        virtual Rozwiazanie* kopiuj() const;
        
        virtual void wyswietlRozwiazanie() const;
        bool czyNiepelneRozwiazanie() const;
        virtual bool czyRozwiazanie() const;
        virtual void wstaw(const int wiersz, const int kolumna, const int liczba);
        virtual void pustaPozycja(int &wiersz, int &kolumna) const;
        virtual bool czyPelna() const;
        virtual list<int> mozliweWartosci(const int wiersz, const int kolumna) const;
        int getNr(const int ktora){ return rozwiazanie[ktora];};
    private:
        int najmniejszaWolna() const;
        bool czyRozlaczneLiczby() const;
        bool czyTrojkiPasuja() const;
        int *rozwiazanie;
        int ileLiczb;
};

/////////////////////////////////////////////////////////

RozwiazanieSudoku::RozwiazanieSudoku( const int wierszy, const int kolumn ): ileKolumn (kolumn), ileWierszy(wierszy)
{
    rozwiazanie = new int*[ileWierszy];
    for(int i=0; i<ileWierszy; i++)
        rozwiazanie[i] = new int[ileKolumn];
}

RozwiazanieSudoku::RozwiazanieSudoku( const RozwiazanieSudoku & rozw ): ileKolumn (rozw.ileKolumn), ileWierszy(rozw.ileWierszy)
{
    rozwiazanie = new int*[ileWierszy];
    for(int i=0; i<ileWierszy; i++)
        rozwiazanie[i] = new int[ileKolumn];
        
    for(int i = 0; i<ileWierszy; ++i)
        for(int j = 0; j<ileKolumn; ++j)
            rozwiazanie[i][j] = rozw.rozwiazanie[i][j];
}
RozwiazanieSudoku::~RozwiazanieSudoku()
{
    for(int i=0; i<ileWierszy; i++)
    {
        if(rozwiazanie[i]!=0)
            delete [] rozwiazanie[i];
        rozwiazanie[i]=0;
    }
    if(rozwiazanie!=0)
        delete [] rozwiazanie;
    rozwiazanie = 0;
}

Rozwiazanie* RozwiazanieSudoku::kopiuj() const
{
    RozwiazanieSudoku *rozwiazanie = new RozwiazanieSudoku(ileWierszy, ileKolumn);
    
    for(int i = 0; i<ileWierszy; ++i)
        for(int j = 0; j<ileKolumn; ++j)
            rozwiazanie->wstaw(i, j, this->rozwiazanie[i][j]);
            
    return rozwiazanie;
}

void RozwiazanieSudoku::wstaw(const int wiersz, const int kolumna, const int liczba)
{
    rozwiazanie[wiersz][kolumna] = liczba;
}

void RozwiazanieSudoku::wyswietlRozwiazanie() const
{
    for(int i = 0; i<ileWierszy; ++i)
    {
        for(int j = 0; j<ileKolumn; ++j)
            cout << rozwiazanie[i][j];
        cout << endl;
    }
}

bool RozwiazanieSudoku::czyPelna() const
{
    for(int i = 0; i<ileWierszy; ++i)
        for(int j = 0; j<ileKolumn; ++j)
            if(rozwiazanie[i][j] == 0) return false;
    return true;
}

void RozwiazanieSudoku::pustaPozycja(int &wiersz, int &kolumna) const
{
    for(int i = 0; i<ileWierszy; ++i)
        for(int j = 0; j<ileKolumn; ++j)
            if(rozwiazanie[i][j] == 0)
            {
                wiersz = i;
                kolumna = j;
                return;
            }
}
bool RozwiazanieSudoku::czyRozlaczneKolumny() const
{
    for(int i = 0; i<ileWierszy; ++i)
    {
        for(int liczba = 1; liczba<=9; ++liczba)
        {
            int ile=0;
            for(int j = 0; j<ileKolumn; ++j)
                if(rozwiazanie[i][j] == liczba)
                    ++ile;
            if(ile>1) return false;
        }
    }
    return true;
}

bool RozwiazanieSudoku::czyRozlaczneWiersze() const
{
    for(int j = 0; j<ileWierszy; ++j)
    {
        for(int liczba = 1; liczba<=9; ++liczba)
        {
            int ile=0;
            for(int i = 0; i<ileKolumn; ++i)
                if(rozwiazanie[i][j] == liczba)
                    ++ile;
            if(ile>1) return false;
        }
    }
    return true;

}

bool RozwiazanieSudoku::czyRozlaczneKwadraty() const
{
    for(int a = 0; a<3; ++a)
        for(int b = 0; b<3; ++b)
        {
            for(int liczba = 1; liczba<=9; ++liczba)
            {
                int ile=0;
                for(int c = 0; c<3; ++c)
                    for(int d = 0; d<3; ++d)
                        if(rozwiazanie[3*a+b][3*c+d] == liczba)
                            ++ile;
                if(ile>1) return false;
            }
        }
    return true;
}

bool RozwiazanieSudoku::czyRozwiazanie() const
{
    return czyRozlaczneKolumny() && czyRozlaczneWiersze() && czyRozlaczneKwadraty();
}

bool RozwiazanieSudoku::czyNiepelneRozwiazanie() const
{
    return czyRozwiazanie();
}

list<int> RozwiazanieSudoku::mozliweWartosci(const int wiersz, const int kolumna) const
{
    list<int> lista;
    for (int i=1;i<=9;i++)
        lista.push_back(i);
    return lista;
}

///////////////////////////////////////////////////////////

RozwiazaniePermutacje::RozwiazaniePermutacje( const RozwiazaniePermutacje & rozw ): ileLiczb (rozw.ileLiczb)
{
    rozwiazanie = new int[ileLiczb];
    
    for(int i=0; i<ileLiczb; i++)
        rozwiazanie[i] = rozw.rozwiazanie[i];
}

RozwiazaniePermutacje::RozwiazaniePermutacje(const int ile): ileLiczb(ile)
{
    rozwiazanie = new int[ileLiczb];
}

RozwiazaniePermutacje::~RozwiazaniePermutacje()
{
    if(rozwiazanie!=0)
        delete [] rozwiazanie;
    rozwiazanie = 0;
}

Rozwiazanie* RozwiazaniePermutacje::kopiuj() const
{
    RozwiazaniePermutacje *rozwiazanie = new RozwiazaniePermutacje(ileLiczb);
    
    for(int i = 0; i<ileLiczb; ++i)
        rozwiazanie->wstaw(i, 0, this->rozwiazanie[i]);
            
    return rozwiazanie;
}

void RozwiazaniePermutacje::wstaw(const int wiersz, const int kolumna, const int liczba) // kolumna jest pomijana
{
    rozwiazanie[wiersz] = liczba;
}

void RozwiazaniePermutacje::wyswietlRozwiazanie() const
{
    for(int i = 0; i<ileLiczb; ++i)
    {
        cout << rozwiazanie[i] << " ";
        if(i%3==2)
            cout << endl;
    }
}

bool RozwiazaniePermutacje::czyPelna() const
{
    for(int i = 0; i<ileLiczb; ++i)
        if(rozwiazanie[i] == -1) return false;
    return true;
}

void RozwiazaniePermutacje::pustaPozycja(int &wiersz, int &kolumna) const // kolumna jest pomijana
{
    for(int i = 0; i<ileLiczb; ++i)
        if(rozwiazanie[i] == -1)
        {
            wiersz = i;
            kolumna = -1;
            return;
        }
}

bool RozwiazaniePermutacje::czyRozlaczneLiczby() const
{
    int ile;
    for(int liczba=0; liczba<ileLiczb; liczba++)
    {
        ile=0;
        for(int i=0; i<ileLiczb; i++)
            if(rozwiazanie[i]==liczba) ile++;
        if(ile>1) return false;
    }
    return true;
}
bool RozwiazaniePermutacje::czyRozwiazanie() const
{
    return czyRozlaczneLiczby(); 
}

bool RozwiazaniePermutacje::czyNiepelneRozwiazanie() const
{
    return czyRozwiazanie();
}

int RozwiazaniePermutacje::najmniejszaWolna() const
{
    int ile;
    for(int liczba=0; liczba<ileLiczb; liczba++)
    {
        ile=0;
        for(int i=0; i<ileLiczb; i++)
            if(rozwiazanie[i]==liczba) ile++;
        if(ile==0) return liczba;
    }
    return -1;
}
/*
list<int> RozwiazaniePermutacje::mozliweWartosci(const int wiersz, const int kolumna) const
{
    list<int> lista;
    if(wiersz%3==0)
        lista.push_back(najmniejszaWolna());
    else 
        for(int i=rozwiazanie[wiersz-1]+1; i<=17; i++)
            lista.push_back(i);
    return lista;
}
*/
list<int> RozwiazaniePermutacje::mozliweWartosci(const int wiersz, const int kolumna) const
{
    list<int> lista;
    for(int i=0; i<ileLiczb; i++)
        lista.push_back(i);
    return lista;
}

///////////////////////////////////////////////////////////

RozwiazaniePetla::RozwiazaniePetla( const RozwiazaniePetla & rozw )
{
    rozwiazanie = new char[(ileWierszy+1) * (ileKolumn+1)];
    
    ileKolumn = rozw.ileKolumn;
    ileWierszy = rozw.ileWierszy;
    dlugoscDrogi = rozw.dlugoscDrogi;
    xStartowy = rozw.xStartowy;
    yStartowy = rozw.yStartowy;
    
    for(int i=0; i<dlugoscDrogi; i++)
        rozwiazanie[i] = rozw.rozwiazanie[i];
}

RozwiazaniePetla::RozwiazaniePetla( const int wierszy, const int kolumn )
{
    rozwiazanie = new char[(ileWierszy+1) * (ileKolumn+1)];
    
    ileKolumn = kolumn;
    ileWierszy = wierszy;
    dlugoscDrogi = 0;
    xStartowy = -1;
    yStartowy = -1;
}
RozwiazaniePetla::~RozwiazaniePetla()
{
    delete [] rozwiazanie;
}
    
Rozwiazanie* RozwiazaniePetla::kopiuj() const
{
    RozwiazaniePetla *rozwiazanie = new RozwiazaniePetla;
    
    rozwiazanie->rozwiazanie = new char[(ileWierszy+1) * (ileKolumn+1)];
    
    rozwiazanie->ileKolumn = ileKolumn;
    rozwiazanie->ileWierszy = ileWierszy;
    rozwiazanie->dlugoscDrogi = dlugoscDrogi;
    rozwiazanie->xStartowy = xStartowy;
    rozwiazanie->yStartowy = yStartowy;
    
    for(int i=0; i<dlugoscDrogi; i++)
        rozwiazanie->rozwiazanie[i] = this->rozwiazanie[i];
    
    return rozwiazanie;
    
}
void RozwiazaniePetla::wyswietlRozwiazanie() const
{
    int tablica[ileWierszy][ileKolumn];
    
    for(int i=0; i<ileWierszy; i++) 
        for(int j=0; j<ileKolumn; j++) 
            tablica[i][j] = 0;
    
    int x = xStartowy;
    int y = yStartowy;
    
    if(dlugoscDrogi>0) tablica[x][y] = 1;
    
    for(int i=0; i<dlugoscDrogi; i++)
    {
        if(rozwiazanie[i]=='d') y++;
        if(rozwiazanie[i]=='g') y--;
        if(rozwiazanie[i]=='p') x++;
        if(rozwiazanie[i]=='l') x--;
        tablica[x][y] = 1;
    }
    for(int i=0; i<ileWierszy; i++) 
    {
        for(int j=0; j<ileKolumn; j++) 
            cout << tablica[i][j] << " ";
        cout <<endl;
    }
}

bool RozwiazaniePetla::czyNiepelneRozwiazanie() const
{
    return true;
}
bool RozwiazaniePetla::czyRozwiazanie() const
{
    return true;
}
void RozwiazaniePetla::wstaw(const int wiersz, const int kolumna, const int liczba) //1 - prawo, 2-dol, 3-lewo, 4-gora, wiersz i kolumna sa pomijane
{
    dlugoscDrogi++;
    if(liczba==1)
        rozwiazanie[dlugoscDrogi] = 'p';
    else if(liczba==2)
        rozwiazanie[dlugoscDrogi] = 'd';
    else if(liczba==3)
        rozwiazanie[dlugoscDrogi] = 'l';
    else if(liczba==4)
        rozwiazanie[dlugoscDrogi] = 'g';

}
void RozwiazaniePetla::pustaPozycja(int &wiersz, int &kolumna) const // zarowno wiersz jak i kolumna sa pomijane
{
    wiersz = 0;
    kolumna = 0;
}

bool RozwiazaniePetla::czyPelna() const // czy pelna petla, na razie nie sprawdzam czy sie przecina
{
    int pion = 0;
    int poziom = 0;
    for(int i=0; i<dlugoscDrogi; i++)
    {
        if(rozwiazanie[i]=='d') pion++;
        if(rozwiazanie[i]=='g') pion--;
        if(rozwiazanie[i]=='p') poziom++;
        if(rozwiazanie[i]=='l') poziom--;
    }
    if(pion==0 && poziom==0) return true;
    return false;
}

//1 - prawo, 2-dol, 3-lewo, 4-gora, wiersz i kolumna sa pomijane
list<int> RozwiazaniePetla::mozliweWartosci(const int wiersz, const int kolumna) const
{
    list<int> lista;
    if(dlugoscDrogi==0)
    {
        lista.push_back(1); // prawo
        lista.push_back(2); // dol
        lista.push_back(3); // lewo
        lista.push_back(4); // gora
    }
    else if(rozwiazanie[dlugoscDrogi-1]=='g') 
    {
        lista.push_back(1); // prawo
        lista.push_back(3); // lewo
        lista.push_back(4); // gora
    }
    else if(rozwiazanie[dlugoscDrogi-1]=='d') 
    {
        lista.push_back(1); // prawo
        lista.push_back(2); // dol
        lista.push_back(3); // lewo
    }
    else if(rozwiazanie[dlugoscDrogi-1]=='p') 
    {
        lista.push_back(1); // prawo
        lista.push_back(2); // dol
        lista.push_back(4); // gora
    }
    else if(rozwiazanie[dlugoscDrogi-1]=='l') 
    {
        lista.push_back(2); // dol
        lista.push_back(3); // lewo
        lista.push_back(4); // gora
    }
    
    return lista;
}

#endif