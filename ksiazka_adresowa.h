#ifndef KSIAZKA_ADRESOWA_H_INCLUDED
#define KSIAZKA_ADRESOWA_H_INCLUDED
#include <iostream>

#include "UzytkownikMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;

public:
    const string nazwaPliku;
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami): uzytkownikMenedzer(nazwaPlikuZUzytkownikami){
    uzytkownikMenedzer.wczytajUzytkownikowZPliku();};
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};
#endif // KSIAZKA_ADRESOWA_H_INCLUDED
