#include <iostream>

#include "ksiazka_adresowa.h"

using namespace std;

int main()
{

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "ksiazka_adresowa.txt");
    char wybor;
    while(true)
    {
        if (ksiazkaAdresowa.czyUzytkownikJestZalogowany())
        {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();
            switch(wybor)
            {
                case '1':
                {
                ksiazkaAdresowa.dodajAdresata();
                break;
                }
                case '4':
                {
                    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                    break;
                }
                case '5':
                {
                    ksiazkaAdresowa.usunAdresata();
                    ksiazkaAdresowa.podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata();
                    break;
                }
                case '6':
                {
                    ksiazkaAdresowa.edytujAdresata();
                    break;
                }
                case '7':
                {
                    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                    break;
                }
                case '8':
                {
                    ksiazkaAdresowa.wylogowanieUzytkownika();
                    break;
                }
                default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();
            switch(wybor)
            {
                case '1':
                {
                    ksiazkaAdresowa.rejestracjaUzytkownika();
                    break;
                }
                case '2':
                {
                    ksiazkaAdresowa.logowanieUzytkownika();
                    break;
                }
                case '9':
                {
                    ksiazkaAdresowa.wylogowanieUzytkownika();
                    ksiazkaAdresowa.wyjscieZProgramu();
                }
                default:
                    cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                    system("pause");
                    break;
            }
        }
    }

        return 0;
}
