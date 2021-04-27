#ifndef PLIKZADRESATAMI_H_INCLUDED
#define PLIKZADRESATAMI_H_INCLUDED
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <string>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
using namespace std;

class PlikZAdresatami
{
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    const string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI;
    //nazwaTymczasowegoPlikuZAdresatami;

    int idOstatniegoAdresata;

    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    bool czyPlikJestPusty(fstream &plikTekstowy);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    int pobierzZPlikuIdOstatniegoAdresata();
    void przepiszDoPlikuTymczasowegoAdresatowOproczUsuwanego( fstream &plikTekstowy, fstream &tymczasowyPlikTekstowy, int idAdresata);
    void przepiszEdytowanegoAdresataZPozostalymiDoPlikuTymczasowego(fstream &plikTekstowy, fstream &tymczasowyPlikTekstowy, Adresat adresat);
//    void zwrocNumerLiniiSzukanegoAdresata(int idAdresata);
//    void edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami);

public:
    PlikZAdresatami(string nazwaPlikuZAdresatami, string nazwaTymczasowegoPlikuZAdresatami): NAZWA_PLIKU_Z_ADRESATAMI (nazwaPlikuZAdresatami),
    NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI(nazwaTymczasowegoPlikuZAdresatami)
    {
        idOstatniegoAdresata = 0;
    };
    vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();
    void dopiszAdresataDoPliku(Adresat adresat);
    int pobierzIdOstatniegoAdresata();
    void usunDaneAdresataZPliku(int idAdresata);
    void usunWybranaLinieWPliku(fstream &odczytywanyPlikTekstowy, int numerUsuwanejLinii);
    int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata);
    void zaktualizujDaneWybranegoAdresata(Adresat adresat);

};

#endif // PLIKZADRESATAMI_H_INCLUDED
