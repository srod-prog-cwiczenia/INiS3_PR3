#include "FormatowanieKolekcji.h"

string FormatowanieKolekcji::formatowanie(const string& txt_p)
{
	constexpr auto znakFormatujacy = '=';
	constexpr auto rozmiarFormatowania = 40;
	if (rozmiarFormatowania <= txt_p.length()) return txt_p;
	unsigned int ile = (rozmiarFormatowania - txt_p.length()) / 2;
	return string(ile, znakFormatujacy) + txt_p + string(ile, znakFormatujacy);
}
