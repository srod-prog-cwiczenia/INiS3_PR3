#pragma once
#include "TestKolekcji.h"
class FormatowanieKolekcji :  public TestKolekcji
{
public:
	FormatowanieKolekcji(int ile) : TestKolekcji(ile) {};
	//po dwukropku podajemy list� inicjowania p�l w postaci: pole(warto��), pole(warto��)
	FormatowanieKolekcji(typywyliczeniowe::TCzymWypelniamy czym):
		TestKolekcji(czym) {};
};

