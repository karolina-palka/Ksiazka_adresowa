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
    int idOstatniegoAdresata;
//    char wybor;
    void wyczyscPamiecWektoraZAdresatami();

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikMenedzer(nazwaPlikuZUzytkownikami),
    adresatMenedzer(nazwaPlikuZAdresatami)
    {
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    };
//    char wybierzOpcjeZMenuGlownego();
//    char wybierzOpcjeZMenuUzytkownika();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void wylogujUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void wyswietlWszystkichAdresatow();
    void dodajAdresata();
    void wyjscieZProgramu();
};
#endif // KSIAZKA_ADRESOWA_H_INCLUDED
