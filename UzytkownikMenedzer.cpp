#include <iostream>
#include "UzytkownikMenedzer.h"

int UzytkownikMenedzer:: pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

Uzytkownik UzytkownikMenedzer:: podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;
    string haslo, login;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    do
    {
        cout << "Podaj login: ";

        uzytkownik.ustawLogin(MetodyPomocnicze::wczytajLinie());

    } while (czyIstniejeLogin( uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    uzytkownik.ustawHaslo(MetodyPomocnicze::wczytajLinie());

    return uzytkownik;
}
int UzytkownikMenedzer:: pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}
bool UzytkownikMenedzer:: czyIstniejeLogin(string login)
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

void UzytkownikMenedzer:: rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
void UzytkownikMenedzer:: wypiszWszystkichUzytkownikow()
{
    for (int i=0; i<uzytkownicy.size(); i++)
    {
            cout <<uzytkownicy[i].pobierzId() << endl;
            cout <<uzytkownicy[i].pobierzLogin() << endl;
            cout <<uzytkownicy[i].pobierzHaslo() << endl;
    }
}

void UzytkownikMenedzer:: logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (itr -> pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika = itr -> pobierzId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}
bool UzytkownikMenedzer:: czyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika >0)
        return true;
    else
        return false;
}
void UzytkownikMenedzer:: zmianaHaslaZalogowanegoUzytkownika(int idZalogowanegoUzytkownika)
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr -> pobierzId() == idZalogowanegoUzytkownika)
        {
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}
void UzytkownikMenedzer:: wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
}
char UzytkownikMenedzer:: wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}