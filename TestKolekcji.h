#pragma once
#include "define.h"
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
	/*
	trzeba dodaæ pole typu funkcyjnego (w C++ nazywa siê to
	,,wskaŸnik na funkcjê'' i ustawiæ go w ka¿dym konstruktorze na null.
	dodaæ metodê ustawiaj¹c¹ to pole i przed wywo³aniem
	formatowania sprawdzaæ czy trzeba uruchomiæ nasz¹ funkcjê
	)
	*/
	TFunkcjaFormatujaca funFormat = NULL;
	virtual string formatowanie(const string &txt_p);
public:
	TestKolekcji(int ile);
	TestKolekcji(typywyliczeniowe::TCzymWypelniamy czym);
	TestKolekcji(char czym);
	~TestKolekcji();
	void wypisanie();
	void ustawienieFunkcjiFormatujacej(TFunkcjaFormatujaca ff);
};

