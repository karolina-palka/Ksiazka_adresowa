#include "AdresatMenedzer.h"

void AdresatMenedzer:: wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    idOstatniegoAdresata = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika);
    cout << "id ostatniego Adresata: " << idOstatniegoAdresata << endl;
}
