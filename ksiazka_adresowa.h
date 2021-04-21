#ifndef KSIAZKA_ADRESOWA_H_INCLUDED
#define KSIAZKA_ADRESOWA_H_INCLUDED
#include <iostream>

#include "UzytkownikMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    int idZalogowanegoUzytkownika;

public:
    const string nazwaPliku;
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami): uzytkownikMenedzer(nazwaPlikuZUzytkownikami){
    uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
//    void zmianaHaslaZalogowanegoUzytkownika();
};
#endif // KSIAZKA_ADRESOWA_H_INCLUDED
