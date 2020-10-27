#pragma once
#include "define.h"
class TMenu
{
private:
	vector<string> tabItemsV;
public:
	void add(string item);
	void addAll(int ilePar, ...);
	unsigned int wybierz();
	TMenu();
	~TMenu();
};

