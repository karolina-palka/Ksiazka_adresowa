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
int KsiazkaAdresowa::logowanieUzytkownika()
{
   idZalogowanegoUzytkownika = uzytkownikMenedzer.logowanieUzytkownika();
}
//void KsiazkaAdresowa:: zmianaHaslaZalogowanegoUzytkownika()
//{
//    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
//}
