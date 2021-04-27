#ifndef ADRESATMENEDZER_H_INCLUDED
#define ADRESATMENEDZER_H_INCLUDED

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"
class AdresatMenedzer
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    vector<Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    int idUsuwanegoAdresata;

    void wyswietlDaneAdresata(Adresat adresat);
     Adresat podajDaneNowegoAdresata();
     int zwrocNumerLiniiSzukanegoAdresata(int idAdresata);
     int podajIdWybranegoAdresata();
     char wybierzOpcjeZMenuEdycja();
     void zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata);
     void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika, string nazwaPlikuTymczasowego="temp.txt")
    : plikZAdresatami(nazwaPlikuZAdresatami, nazwaPlikuTymczasowego), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    char wybierzOpcjeZMenuUzytkownika();
    void wyswietlWszystkichAdresatow();
    void dodajAdresata();
    int usunAdresata();
    void podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata();
    void edytujAdresata();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
};

#endif // ADRESATMENEDZER_H_INCLUDED
