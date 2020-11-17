#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdarg>
#include <cassert>
#include <algorithm>
using namespace std;
/* wskaŸnik na funkcjê formatuj¹c¹: */
/*zadanie: zmieniæ (=zoptymalizowaæ) typ
TFunkcjaFormatuj¹ca jako posiadaj¹ca parametr const string & zamiast string*/
typedef string(*TFunkcjaFormatujaca)(const string&);

