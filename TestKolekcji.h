#pragma once
#include <string>
#include <vector>
// czym wype³niaæ, sta³e:
#define CW_DNIAMI_TYGODNIA 't'
#define CW_LICZBAMI        'l'
// a mog¹ byæ takie np. definicje:
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
public:
	TestKolekcji(int ile);
	TestKolekcji(typywyliczeniowe::TCzymWypelniamy czym);
	TestKolekcji(char czym);
	~TestKolekcji();
	void wypisanie();
};

