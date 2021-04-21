#ifndef PLIKZUZYTKOWNIKAMI_H_INCLUDED
#define PLIKZUZYTKOWNIKAMI_H_INCLUDED
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "uzytkownik.h"
#include "MetodyPomocnicze.h"
using namespace std;

class PlikZUzytkownikami
{
    const string nazwaPlikuZUzytkownikami;
//    fstream plikTekstowy;


    bool czyPlikJestPusty();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
//    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);
public:
    PlikZUzytkownikami(string NAZWAPLIKUZUZYTKOWNIKAMI): nazwaPlikuZUzytkownikami (NAZWAPLIKUZUZYTKOWNIKAMI){};
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector<Uzytkownik> wczytajUzytkownikowZPliku();

};
#endif // UZYTKOWNIKMENEDZER_H_INCLUDED
