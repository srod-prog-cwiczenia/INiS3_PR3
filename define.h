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
/* wskaŸnik na funkcjê formatuj¹c¹: */
/*zadanie: zmieniæ (=zoptymalizowaæ) typ
TFunkcjaFormatuj¹ca jako posiadaj¹ca parametr const string & zamiast string*/
typedef string(*TFunkcjaFormatujaca)(const string&);
/*definicja struktury TOsoba: */
struct TOsoba {
	string imie, nazwisko;
	unsigned int wiek;
	//konstruktor domyœlny:
	TOsoba(): wiek(0) {};
	//konstruktor:
	TOsoba(const string &imie_p, const string &nazwisko_p, const unsigned int &wiek_p) :
		imie(imie_p), nazwisko(nazwisko_p), wiek(wiek_p) {}
	operator string() const { return imie + " " + 
		nazwisko + " " + to_string(wiek); };
	/*
	* przeci¹¿yæ < mo¿na tak, ale map tego nie rozumie ;). Wiêc stosujemy 
	* przeci¹¿enie jak ni¿ej : friend, etc.
	* 
	bool operator < (const TOsoba& a) {
		return nazwisko + " " + imie + " " + to_string(wiek) <
			a.nazwisko + " " + a.imie + " " + to_string(a.wiek);
	}*/
	friend bool operator < (const TOsoba &a, const TOsoba &b) {
		/*return a.nazwisko + " " + a.imie + " " + to_string(a.wiek) <
			b.nazwisko + " " + b.imie + " " + to_string(b.wiek);
		TODO: to nie jest do koñca poprawne porównanie, mo¿e to bêdzie dobrze,
		* ale bezpieczniej jest zrobiæ tak: pad(nazwisko, 50) itditd.
		* pad(string, int) to uzupe³nienie spacjami do zadanej d³ugoœci
		*/
//na szczêœcie jest mo¿liwe rozwi¹zanie w zupe³noœci niekontrowersyjne:
		if (a.nazwisko < b.nazwisko) return true;
		if (a.nazwisko > b.nazwisko) return false;
		if (a.imie < b.imie) return true;
		if (a.imie > b.imie) return false;
		if (a.wiek < b.wiek) return true;
		return false;
	}
};

