#include <iostream>
#include "ksiazka_adresowa.h"
using namespace std;

void KsiazkaAdresowa:: rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
//    dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik KsiazkaAdresowa:: podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;
    string haslo, login;

//    uzytkownik.id = pobierzIdNowegoUzytkownika();
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    do
    {
        cout << "Podaj login: ";
//        login = wczytajLinie();
//        uzytkownik.ustawLogin(login);
        uzytkownik.ustawLogin(wczytajLinie());
//        cin >> login;
//        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin( uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
//    cin >> haslo;
//    haslo = wczytajLinie();
//    uzytkownik.ustawHaslo(haslo);
    uzytkownik.ustawHaslo(wczytajLinie());
//    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int KsiazkaAdresowa:: pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool KsiazkaAdresowa:: czyIstniejeLogin(string login)
{
    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if (login == uzytkownicy[i].pobierzLogin())
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

string KsiazkaAdresowa:: wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}
void KsiazkaAdresowa:: wypiszWszystkichUzytkownikow()
{
    for (int i=0; i<uzytkownicy.size(); i++)
    {
            cout <<uzytkownicy[i].pobierzId() << endl;
            cout <<uzytkownicy[i].pobierzLogin() << endl;
            cout <<uzytkownicy[i].pobierzHaslo() << endl;
    }
}
