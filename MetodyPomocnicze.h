#ifndef METODYPOMOCNICZE_H_INCLUDED
#define METODYPOMOCNICZE_H_INCLUDED
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

//#include "MetodyPomocnicze.h"
using namespace std;

class MetodyPomocnicze
{
public:
    static string wczytajLinie();
    static string konwerjsaIntNaString(int liczba);
};
#endif
