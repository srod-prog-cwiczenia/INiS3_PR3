#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdarg>
#include <cassert>
#include <algorithm>
using namespace std;
/* wska�nik na funkcj� formatuj�c�: */
/*zadanie: zmieni� (=zoptymalizowa�) typ
TFunkcjaFormatuj�ca jako posiadaj�ca parametr const string & zamiast string*/
typedef string(*TFunkcjaFormatujaca)(const string&);

