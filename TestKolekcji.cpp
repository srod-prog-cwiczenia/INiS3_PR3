#include "TestKolekcji.h"
#include <iostream>
#include <cassert>
using namespace typywyliczeniowe;

TestKolekcji::TestKolekcji(int ile)
{
	for (int i = 0; i < ile; i++) {
		vec.push_back(to_string(i));
		//vec.push_back("" + i);
	}
}

TestKolekcji::TestKolekcji(TCzymWypelniamy czym)
{
	switch (czym) {
	case TCzymWypelniamy::cwDniTygodnia:
		   for (string txt : {"Pon", "Wt", "Œr", "Czw", "Pia", "So", "Nie"}) {
			   vec.push_back(txt);
		   }
	       break;
	case TCzymWypelniamy::cwLiczby: {
	  	  int ile = 10;
		  for (int i = 0; i < ile; i++) {
			  vec.push_back(to_string(i));
			//vec.push_back("" + i);
		  }
		  break;
	}
		default:
			assert(!"Nieobs³u¿ony typ wyliczeniowy czymwypelniamy");
			break;
	}
}

TestKolekcji::TestKolekcji(char czym)
{
	switch (czym) {
	case CW_DNIAMI_TYGODNIA:
	    //........ tutaj kod do wype³niania wektora nazwami dni tygodnia
		break;
	case CW_LICZBAMI:
		// ......... tutaj kod to wype³niania wektora liczbami
		break;
	}
}

TestKolekcji::~TestKolekcji()
{
}

void TestKolekcji::wypisanie()
{
	for (string txt : vec) {
		cout << txt << endl;
	}
}
