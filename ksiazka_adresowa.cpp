#include <iostream>
#include "ksiazka_adresowa.h"
using namespace std;


void KsiazkaAdresowa:: rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}
char KsiazkaAdresowa:: wybierzOpcjeZMenuGlownego()
{
    return uzytkownikMenedzer.wybierzOpcjeZMenuGlownego();
}
char KsiazkaAdresowa:: wybierzOpcjeZMenuUzytkownika()
{
    return adresatMenedzer->wybierzOpcjeZMenuUzytkownika();
}
void KsiazkaAdresowa:: wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}
void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}
void KsiazkaAdresowa:: wyjscieZProgramu()
{
    exit(0);
}
void KsiazkaAdresowa:: wylogowanieUzytkownika()
{
    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
    cout << "Wylogowano" << endl;

}
void KsiazkaAdresowa:: zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
}
void KsiazkaAdresowa:: wyswietlWszystkichAdresatow()
{
    adresatMenedzer->wyswietlWszystkichAdresatow();
}
void KsiazkaAdresowa:: dodajAdresata()
{
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer->dodajAdresata();
    }
    else
    {
        cout<< "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}
bool KsiazkaAdresowa:: czyUzytkownikJestZalogowany()
{
    uzytkownikMenedzer.czyUzytkownikJestZalogowany();
}
void KsiazkaAdresowa:: usunAdresata()
{
    adresatMenedzer->usunAdresata();
}
void KsiazkaAdresowa:: podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata()
{
    adresatMenedzer->podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata();
}
