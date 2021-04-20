#ifndef KSIAZKA_ADRESOWA_H_INCLUDED
#define KSIAZKA_ADRESOWA_H_INCLUDED
#include <iostream>

#include "UzytkownikMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;

public:
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};
#endif // KSIAZKA_ADRESOWA_H_INCLUDED
