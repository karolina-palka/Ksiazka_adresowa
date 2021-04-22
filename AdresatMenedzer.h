#ifndef ADRESATMENEDZER_H_INCLUDED
#define ADRESATMENEDZER_H_INCLUDED

#include "Adresat.h"
#include "PlikZAdresatami.h"
class AdresatMenedzer
{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    vector<Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
public:
    AdresatMenedzer(string nazwaPlikuZAdresatami): plikZAdresatami(nazwaPlikuZAdresatami){};
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

};

#endif // ADRESATMENEDZER_H_INCLUDED
