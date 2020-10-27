#pragma once
#include "define.h"
// czym wype�nia�, sta�e:
#define CW_DNIAMI_TYGODNIA 't'
#define CW_LICZBAMI        'l'
// a mog� by� takie np. definicje:
#define MAX_ILOSC_LINII_NA_STRONIE_WYDRUKU 25
using namespace std;
namespace typywyliczeniowe {
	enum class TCzymWypelniamy {
		cwDniTygodnia, cwLiczby
	};
}
class TestKolekcji
{
private:
	vector<string> vec;
	virtual string formatowanie(const string &txt_p);
public:
	TestKolekcji(int ile);
	TestKolekcji(typywyliczeniowe::TCzymWypelniamy czym);
	TestKolekcji(char czym);
	~TestKolekcji();
	void wypisanie();
};
