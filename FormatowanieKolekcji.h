#pragma once
#include "TestKolekcji.h"
class FormatowanieKolekcji :  public TestKolekcji
{
public:
	FormatowanieKolekcji(int ile) : TestKolekcji(ile) {};
	//po dwukropku podajemy listê inicjowania pól w postaci: pole(wartoœæ), pole(wartoœæ)
	FormatowanieKolekcji(typywyliczeniowe::TCzymWypelniamy czym):
		TestKolekcji(czym) {};
};

