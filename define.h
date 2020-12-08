#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cstdarg>
#include <cassert>
#include <algorithm>
using namespace std;
/* wska�nik na funkcj� formatuj�c�: */
/*zadanie: zmieni� (=zoptymalizowa�) typ
TFunkcjaFormatuj�ca jako posiadaj�ca parametr const string & zamiast string*/
typedef string(*TFunkcjaFormatujaca)(const string&);
/*definicja struktury TOsoba: */
struct TOsoba {
	string imie, nazwisko;
	unsigned int wiek;
	//konstruktor domy�lny:
	TOsoba(): wiek(0) {};
	//konstruktor:
	TOsoba(const string &imie_p, const string &nazwisko_p, const unsigned int &wiek_p) :
		imie(imie_p), nazwisko(nazwisko_p), wiek(wiek_p) {}
	operator string() const { return imie + " " + 
		nazwisko + " " + to_string(wiek); };
};

