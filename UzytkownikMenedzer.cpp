#include <iostream>
#include "UzytkownikMenedzer.h"
//#include "uzytkownik.h"

//using namespace std;

Uzytkownik UzytkownikMenedzer:: podajDaneNowegoUzytkownika()
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
        uzytkownik.ustawLogin(MetodyPomocnicze::wczytajLinie());
//        cin >> login;
//        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin( uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
//    cin >> haslo;
//    haslo = wczytajLinie();
//    uzytkownik.ustawHaslo(haslo);
    uzytkownik.ustawHaslo(MetodyPomocnicze::wczytajLinie());
//    uzytkownik.ustawHaslo(haslo);

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
