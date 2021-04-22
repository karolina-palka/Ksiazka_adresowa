#ifndef KSIAZKA_ADRESOWA_H_INCLUDED
#define KSIAZKA_ADRESOWA_H_INCLUDED
#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenedzer;
    int idZalogowanegoUzytkownika;

public:
//    const string nazwaPliku;
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikMenedzer(nazwaPlikuZUzytkownikami),
    adresatMenedzer(nazwaPlikuZAdresatami)
    {
    uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();
};
#endif // KSIAZKA_ADRESOWA_H_INCLUDED
