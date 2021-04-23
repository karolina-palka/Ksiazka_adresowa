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
    const string nazwaPlikuZAdresatami;

//    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    bool czyPlikJestPusty(fstream &plikTekstowy);
public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI): nazwaPlikuZAdresatami (NAZWAPLIKUZADRESATAMI){};
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(vector<Adresat> &adresaci, int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();
    void dopiszAdresataDoPliku(Adresat adresat);

};


#endif // PLIKZADRESATAMI_H_INCLUDED
