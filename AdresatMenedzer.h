#ifndef ADRESATMENEDZER_H_INCLUDED
#define ADRESATMENEDZER_H_INCLUDED

#include "Adresat.h"
#include "PlikZAdresatami.h"
class AdresatMenedzer
{
    int idOstatniegoAdresata;
//    int idUsunietegoAdresata;
    vector<Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    void wyswietlDaneAdresata(Adresat adresat);
public:
    AdresatMenedzer(string nazwaPlikuZAdresatami): plikZAdresatami(nazwaPlikuZAdresatami){};
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();
};

#endif // ADRESATMENEDZER_H_INCLUDED
