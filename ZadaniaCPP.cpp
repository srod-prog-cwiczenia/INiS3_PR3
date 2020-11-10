// Zadania3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "TestKolekcji.h"
#include "FormatowanieKolekcji.h"
#include "TMenu.h"

class Zadania {
public:
    static void formatowanieKolekcji() {
        // wskaźnik na obiekt
        FormatowanieKolekcji* fk = new FormatowanieKolekcji(10);
        fk->wypisanie();
        delete fk;

        cout << "\n--------------------------\n";
        // obiekt statyczny:
        FormatowanieKolekcji tks(typywyliczeniowe::TCzymWypelniamy::cwDniTygodnia);
        tks.wypisanie();
    };
    static void zadaniaZeWskaznikow() {
        //Zadanie nr 1: poniższy kod liczy sumę elementów tablicy,
        //napisać go używając wskaźników:
        int tab[] = { 13, 7, 8, 1, 0}; //0 oznacza koniec tablicy!
        int suma = 0;
        for (auto i : tab)
            suma += i;
        cout << "Suma: " << suma << endl;

        //(...)a teraz wskaźnikami: (wymagane zaznaczenie konca tab przez 0)
        int* wsk = tab;
        suma = 0;
        while (*wsk) {
            suma += *(wsk++);
        };
        //Zadanie domowe TODO: Zbadać czy działa poprawnie (przypuszczalnie tak)
        //poniższy kod. Jeśli jest poprawny to rozgryźć dlaczego?
        //(uwaga: wymagane zaznaczenie konca tab przez 0)
        //(uwaga: w tym ,,trickowym'' rozwiązaniu jak poniżej używamy 
        // , - wyrażenie (a,b) oznacza oblicz a oblicz b i weź wartość b)
              //while (suma += *wsk, *(++wsk)); //uwaga: przypadek {0} będzie działał źle
        cout << "Suma: " << suma << endl;

        wsk = tab; suma = 0;
        //wyliczenie sumy bez zakładania że ostatni element tablicy to zero:
        for (int i = 0; i < sizeof(tab) / sizeof(tab[0]); i++)
            suma += *wsk++;
        cout << "Suma: " << suma << endl;

        /*
          Zadanie: Mamy tablicę dwuwymiarową: int tabM[10][10];
          uzupełnić ją iloczynami (`a la tabliczka mnożenia).
          ale używając wskaźników:

        */
        int tabM[10][10];
        /*
          rozwiązanie klasyczne:
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                tabM[i][j] = (i + 1) * (j + 10);*/
        //rozwiązanie ze wskaźnikami:
        wsk = tabM[0];
        for (int k = 0; k < 100; k++)
            *wsk++ = (k / 10 + 1) * (k % 10 + 1);
/* tak nie robimy: int** wsk2 = (int**) tabM;
*  bo tabM nie da się zrzutować (sensownie) na podwójny wskaźnik
* bo tablica dwuwymiarowa to NIE JEST podwójny wskaźnik
*/
        //albo inna wersja używająca rzutowania:
//        wsk = (int*)tabM;
        cout << string(50, '=') << endl;
        //teraz drukujemy tablicę:
        for (int i = 0; i < 10; (cout << '\n', i++))
            for (int j = 0; j < 10; j++)
                cout << tabM[i][j] << " ";
        cout << endl;
    }
    static void zadaniaZKolekcji() {
        //TODO zainicjowac kolekcje lista podaną listą intów,
        //policzyć sumę (różnymi metodami m.in. użyć iteratora).
        list<int> li({ 13, 7, 8, 1 });
// sposób nr 1 - za pomocą pętli ,,foreach"        
        int suma = 0;
        for (auto i : li)
            suma += i;
        cout << "Suma: " << suma << endl;
//sposób nr 2 - za pomocą iteratora:
        suma = 0;
          // auto poniżej rozwija się do typu: list<int>::iterator
        for (auto ite = li.begin(); ite != li.end(); ite++) {
            suma += *ite;
        }
        cout << "Suma: " << suma << endl;
    }
};

int main()
{
    for (;;) {
        TMenu* mnu = new TMenu();
        mnu->addAll(3, "Testy kolekcji", "Wskazniki", "Zadania z kolekcji STL");
        switch (mnu->wybierz()) {
        case 0:
            exit(0);
        case 1:
            Zadania::formatowanieKolekcji();
            break;
        case 2:
            Zadania::zadaniaZeWskaznikow();
            break;
        case 3:
            Zadania::zadaniaZKolekcji();
            break;
        }
        delete mnu;
    }
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
