#ifndef PLIKTEKSTOWY_H_INCLUDED
#define PLIKTEKSTOWY_H_INCLUDED

#include <fstream>
#include <string>

using namespace std;

class PlikTekstowy
{
    const string NAZWA_PLIKU;

public:
    PlikTekstowy(string nazwaPliku): NAZWA_PLIKU(nazwaPliku){};
    bool czyPlikJestPusty(fstream &plikTekstowy);
    string pobierzNazwePliku();
};

#endif // PLIKTEKSTOWY_H_INCLUDED
