#include <iostream>
//#include <windows.h>
#include "ksiazka_adresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
//    ksiazkaAdresowa.rejestracjaUzytkownika();
//    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.logowanieUzytkownika();
    return 0;
}
