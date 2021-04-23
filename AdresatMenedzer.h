#ifndef ADRESATMENEDZER_H_INCLUDED
#define ADRESATMENEDZER_H_INCLUDED
#include <algorithm>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"
class AdresatMenedzer
{
    int idOstatniegoAdresata;
//    char wybor;
    vector<Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    void wyswietlDaneAdresata(Adresat adresat);
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami): plikZAdresatami(nazwaPlikuZAdresatami){};
//    char wybierzOpcjeZMenuUzytkownika();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();
    int dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void wyczyscPamiecWektoraZAdresatami();

};

#endif // ADRESATMENEDZER_H_INCLUDED
