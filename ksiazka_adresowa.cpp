#include <iostream>
#include "ksiazka_adresowa.h"
using namespace std;


void KsiazkaAdresowa:: rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}
/*char KsiazkaAdresowa:: wybierzOpcjeZMenuGlownego()
{
    wybor = uzytkownikMenedzer.wybierzOpcjeZMenuGlownego();
}*/
/*char KsiazkaAdresowa:: wybierzOpcjeZMenuUzytkownika()
{
    wybor = adresatMenedzer.wybierzOpcjeZMenuUzytkownika();
}*/
void KsiazkaAdresowa:: wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}
void KsiazkaAdresowa::logowanieUzytkownika()
{
    idZalogowanegoUzytkownika = uzytkownikMenedzer.logowanieUzytkownika();
}
void KsiazkaAdresowa:: wyjscieZProgramu()
{
    exit(0);
}

void KsiazkaAdresowa:: wylogujUzytkownika()
{
    if (idZalogowanegoUzytkownika!=0)
    {
        idZalogowanegoUzytkownika =0;
        adresatMenedzer.wyczyscPamiecWektoraZAdresatami();
        cout << "Wylogowano" << endl;
    }
}
void KsiazkaAdresowa:: zmianaHaslaZalogowanegoUzytkownika()
{
    if (idZalogowanegoUzytkownika!=0)
    {
        uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
    }
}
void KsiazkaAdresowa:: wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    idOstatniegoAdresata = adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}
void KsiazkaAdresowa:: wyswietlWszystkichAdresatow()
{
    if (idZalogowanegoUzytkownika!=0)
    {
        adresatMenedzer.wyswietlWszystkichAdresatow();
    }
}
void KsiazkaAdresowa:: dodajAdresata()
{
    if (idZalogowanegoUzytkownika!=0)
    {
        idOstatniegoAdresata = adresatMenedzer.dodajAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);
    }
}
