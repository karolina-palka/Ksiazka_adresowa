#include "PlikZAdresatami.h"

int PlikZAdresatami:: pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
}
vector<Adresat> PlikZAdresatami:: wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    vector<Adresat> adresaci;
 //zdefiniowanie na nowo poni¿szej zmiennej powoduje jej zas³oniêcie i jej wartoœæ nie jest przekazywana do sk³¹dowej klasy o tej samej nazwie!!!
//    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
        return adresaci;
}
int PlikZAdresatami:: pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    string liczba = MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata);
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(liczba);
    return idAdresata;
}
Adresat PlikZAdresatami:: pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}
int PlikZAdresatami:: pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}
void PlikZAdresatami:: dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty(plikTekstowy) == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    idOstatniegoAdresata++;
    plikTekstowy.close();
    system("pause");
}
string PlikZAdresatami:: zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}
bool PlikZAdresatami:: czyPlikJestPusty(fstream &plikTekstowy)
{
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}
void PlikZAdresatami:: usunDaneAdresataZPliku(int idAdresata)
{
    fstream plikTekstowy, tymczasowyPlikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true && idAdresata != 0)
    {
        przepiszDoPlikuTymczasowegoAdresatowOproczUsuwanego(plikTekstowy, tymczasowyPlikTekstowy, idAdresata);
    }
    plikTekstowy.close();
    tymczasowyPlikTekstowy.close();

    usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
    zmienNazwePliku(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, NAZWA_PLIKU_Z_ADRESATAMI);
}

void PlikZAdresatami:: przepiszDoPlikuTymczasowegoAdresatowOproczUsuwanego(fstream &plikTekstowy, fstream &tymczasowyPlikTekstowy, int idAdresata)
{
//    bool czyIstniejeAdresat = false;
    int numerLiniiWPlikuTekstowym = 1, numerLiniiWPlikuTymczasowym = 1;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";

    while(getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
    {
        if(idAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
        { }
//           czyIstniejeAdresat = true;
        else
        {
            if (numerLiniiWPlikuTymczasowym ==1)
            {
                tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
                numerLiniiWPlikuTekstowym++;
                numerLiniiWPlikuTymczasowym++;
            }
            else
            {
                tymczasowyPlikTekstowy << endl << daneJednegoAdresataOddzielonePionowymiKreskami;
                numerLiniiWPlikuTekstowym++;
                numerLiniiWPlikuTymczasowym++;
            }
        }
    }
}

void PlikZAdresatami:: usunPlik(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}
void PlikZAdresatami:: zmienNazwePliku(string staraNazwa, string nowaNazwa)
{
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}
int PlikZAdresatami:: podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata)
{
    if (idUsuwanegoAdresata == idOstatniegoAdresata)
        return pobierzZPlikuIdOstatniegoAdresata();
    else
        return idOstatniegoAdresata;
}
int PlikZAdresatami:: pobierzZPlikuIdOstatniegoAdresata()
{
//    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {}
            daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
            plikTekstowy.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
//    cout << "idOstatniegoAdresata: " << idOstatniegoAdresata << endl;
//    system("pause");
    return idOstatniegoAdresata;
}

void PlikZAdresatami:: zaktualizujDaneWybranegoAdresata(Adresat adresat)
{
    fstream plikTekstowy, tymczasowyPlikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    int idAdresata = adresat.pobierzId();
    if (plikTekstowy.good() == true && idAdresata != 0)
    {
        przepiszEdytowanegoAdresataZPozostalymiDoPlikuTymczasowego(plikTekstowy, tymczasowyPlikTekstowy, adresat);
    }
    plikTekstowy.close();
    tymczasowyPlikTekstowy.close();

    usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
    zmienNazwePliku(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, NAZWA_PLIKU_Z_ADRESATAMI);
}
void PlikZAdresatami:: przepiszEdytowanegoAdresataZPozostalymiDoPlikuTymczasowego(fstream &plikTekstowy, fstream &tymczasowyPlikTekstowy, Adresat adresat)
{
    string daneJednegoAdresataOddzielonePionowymiKreskami = "", liniaZDanymiAdresata="";
//    bool czyIstniejeAdresat = false;
    int numerLiniiWPlikuTekstowym = 1, numerLiniiWPlikuTymczasowym = 1;
    int idAdresata = adresat.pobierzId();

    while(getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
    {
        if(idAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
        {
//            czyIstniejeAdresat = true;
            liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
            if (numerLiniiWPlikuTymczasowym == 1)
            {
                tymczasowyPlikTekstowy << liniaZDanymiAdresata;
            }
            else
            {
                tymczasowyPlikTekstowy << endl << liniaZDanymiAdresata;
            }
        }
        else
        {
            if (numerLiniiWPlikuTymczasowym == 1)
            {
                tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
            }
            else
            {
                tymczasowyPlikTekstowy << endl << daneJednegoAdresataOddzielonePionowymiKreskami;
            }
        }
        numerLiniiWPlikuTekstowym++;
        numerLiniiWPlikuTymczasowym++;
    }
}
