#include <iostream>
#include "ksiazka_adresowa.h"
using namespace std;


void KsiazkaAdresowa:: rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa:: wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}
void KsiazkaAdresowa::logowanieUzytkownika()
{
   idZalogowanegoUzytkownika = uzytkownikMenedzer.logowanieUzytkownika();
}
void KsiazkaAdresowa:: zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
}
int KsiazkaAdresowa:: wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}
