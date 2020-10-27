#include "TMenu.h"

void TMenu::add(string item)
{
	tabItemsV.push_back(item);
}

void TMenu::addAll(int ilePar, ...)
{
	va_list vl;
	va_start(vl, ilePar);
	for (int j = 0; j < ilePar; j++) {
		char *lancuch = va_arg(vl, char*);
		string txt = (string)lancuch;
		add(txt);
	}
	va_end(vl);
}

unsigned int TMenu::wybierz()
{
	/*for (unsigned int j = 0; j < tabItemsV.size(); j++)
		cout << tabItemsV[j] << endl;*/
	//albo mo¿na tak: for (auto txt : tabItemsV) 
	for (string txt: tabItemsV)
		cout << txt << endl;
	unsigned int opcja;
	do {
		cin >> opcja;
	} while (opcja > tabItemsV.size());
	return opcja;
}

TMenu::TMenu()
{
}

TMenu::~TMenu()
{
}
