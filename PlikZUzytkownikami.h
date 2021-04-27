#ifndef PLIKZUZYTKOWNIKAMI_H_INCLUDED
#define PLIKZUZYTKOWNIKAMI_H_INCLUDED
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "PlikTekstowy.h"
#include "uzytkownik.h"
#include "MetodyPomocnicze.h"
using namespace std;

class PlikZUzytkownikami: public PlikTekstowy
{
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    PlikZUzytkownikami(string nazwaPlikuZUzytkownikami): PlikTekstowy(nazwaPlikuZUzytkownikami){};
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector<Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);

};
#endif // UZYTKOWNIKMENEDZER_H_INCLUDED
