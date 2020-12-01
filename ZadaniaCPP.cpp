// Zadania3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "TestKolekcji.h"
#include "FormatowanieKolekcji.h"
#include "TMenu.h"

/*szablon do zadania zadaniaZSzablonow: */
template <typename T>
class TTrojka {
public:
    T x1, x2, x3;
    TTrojka(const T &a1, const T &a2, const T &a3) : x1(a1), x2(a2), x3(a3) {};
    T getElement(const int& ktory) {
        switch (ktory) {
        case 1:
            return x1; 
        case 2:
            return x2; 
        case 3:
            return x3; 
        default:
            assert(!"Nieprawidlowy indeks w getElement w szablonie TTrojka");
            return x3; // tylko po to by pozbyć się warninga nr C4715.
        }
    }
};

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

        /* napisać formatowanie wydruku ale z użyciem
        podstawienia pod wskaźnik na funkcję a nie j.w. (z użyciem metody wirtualnej) */
/* sposób na utworzenie obiektu dynamicznego: TestKolekcji *tk = new(TestKolekcji) 
        { typywyliczeniowe::TCzymWypelniamy::cwDniTygodnia };*/
        cout << endl << "Formatowanie z uzyciem wskaznikow na funkcje: " << endl;
        TestKolekcji tk = { typywyliczeniowe::TCzymWypelniamy::cwDniTygodnia };
        tk.ustawienieFunkcjiFormatujacej(
            [](const string &txt_p) -> string { return txt_p + "."; }
        );
        tk.wypisanie();
    };
    static void zadaniaZeWskaznikow() {
        //Zadanie nr 1: poniższy kod liczy sumę elementów tablicy,
        //napisać go używając wskaźników:
        int tab[] = { 13, 7, 8, 1, 0}; //0 oznacza koniec tablicy!
        int suma = 0;
        for (auto i : tab)
            suma += i;
        cout << "Suma: " << suma << endl;
        assert(suma == 29 && "Zle policzona suma!");

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
        assert(suma == 29 && "Zle policzona suma!");

        wsk = tab; suma = 0;
        //wyliczenie sumy bez zakładania że ostatni element tablicy to zero:
        for (int i = 0; i < sizeof(tab) / sizeof(tab[0]); i++)
            suma += *wsk++;
        cout << "Suma: " << suma << endl;
        assert(suma == 29 && "Zle policzona suma!");
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

        //wstawka modyfikacyjna by przetestować że intM[nr] jest typu int*:
        //wsk = tabM[3]; for (int l = 0; l < 10; (l++,*wsk++ = 7));

        cout << string(50, '=') << endl;
        //teraz drukujemy tablicę:
        for (int i = 0; i < 10; (cout << '\n', i++))
            for (int j = 0; j < 10; j++)
                cout << tabM[i][j] << '\t';
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
    static void zadaniaZDzialanNaKolekcjach() {
        /*na elementach kolekcji można ,,uruchamiać'' funkcje*/
        list<int> li({ 13, 7, 8, 1 });
        /*wypisać zawartość kolekcji li wyliczając kwadraty liczb 
        za pomocą modułu #include <algorithm> i funkcji for_each*/
        int licznik;
        auto kwadrat = [&licznik](int ii)-> void {cout << ++licznik << ". "
            << ii << ": " << ii * ii << endl; };
        /*słowo kluczowe mutable oznacza że zmienne
        zewnętrzne (licznik) można zmieniać i są tworzone kopie
        lokalne po każdorazowym wywołaniu */
        cout << string(50, '-') << endl;
        licznik = 0;
        for_each(li.begin(), li.end(), kwadrat);
        cout << string(50, '-') << endl;
        licznik = 0;
        for_each(li.begin(), li.end(), kwadrat);
        cout << string(50, '-') << endl;
        licznik = 0;
        for (int jj = 0; jj < 8; jj++)
            kwadrat(jj);
        cout << string(50, '-') << endl;
/*TODO: zauważmy że licznik w ostatniej pętli (poniżej) 
nie resetuje się, wyjaśnić - dlaczego ? Rozwiązanie problemu:
mozna np. podawać w liście zewnętrznych zmiennych lambda funkcji ([...])
wskaźnik na licznik i inicjować go za każdym razem na 0. */
        licznik = 0;
        for (int jj = 9; jj < 12; jj++)
            kwadrat(jj);
        cout << string(50, '-') << endl;
        /*zadanie: wymyśleć modyfikację funkcji kwadrat by wypisywała licznik
        wierszy. Rozwiązanie - lambda funkcja i modyfikator mutable*/

/*        cout << "Zawartosc listy: " << endl;
        for (auto i : li)
            cout << i << "\t";
        cout << endl;*/
    }
    /* zadanie : przepisać to samo ale używając funktorów */
    static void zadaniaZDzialanNaKolekcjachFunktory() { 
        /*to jest funktor, jest to struktura którą używamy jako funkcję : */
        struct Kwadraty {
        private:
            int licznik;
        public:
            Kwadraty() : licznik(0) {};
            Kwadraty(int poczatkowaWartoscLicznika) :
                licznik(poczatkowaWartoscLicznika) {};/*dodatkowy konstruktor inicjujacy licznik */
            void operator()(int ii) {
                cout << ++licznik << ". " << ii << ": " << ii * ii << endl;
            }
            void reset() { licznik = 0; }
        };
    
        list<int> li({ 13, 7, 8, 1 });
        cout << string(50, '-') << endl;
        for_each(li.begin(), li.end(), Kwadraty());
        cout << string(50, '-') << endl;
        for_each(li.begin(), li.end(), Kwadraty());
        cout << string(50, '-') << endl;
        Kwadraty kw;
        for (int jj = 0; jj < 8; jj++)
            kw(jj);
        cout << string(50, '-') << endl;
        kw.reset();
        for (int jj = 9; jj < 12; jj++)
            kw(jj);
        cout << string(50, '-') << endl;
    }
    static void zadaniaZModyfikacjiKolekcjiFunktory() {
        /*napisać funktor który zamienia zawartość łańcucha na duże litery
        i zastosować go do kolekcji łańcuchów. czy da się to zrealizować za pomocą
        lambda funkcji? */
        //lambda funkcja:
        auto duzeLitery = [](const string& txt)->string {
            string txtL(txt); for (auto& c : txtL) c = toupper(c); return txtL; 
        };
        //funktor:
        struct DuzeLiteryFun {
            string operator()(const string &txt) {
              string txtL(txt); for (auto& c : txtL) c = toupper(c); return txtL;
            }
        };
        vector<string> inS = { "Merkury", "Wenus", "Ziemia", "Mars", "Jowisz", "Saturn",
           "Uran", "Neptun", "Pluton" };
        //instrukcja która przekształca (transformuje ;) ) elementy kolekcji
        // to transform (#include <algorithm>)
        vector<string> outS1(inS.size()); //bo wektor wynikowy ma być zainicjowany pustymi łańcuchami do zadanej długości
        transform(inS.begin(), inS.end(), outS1.begin(), duzeLitery);
        cout << "Transformacja przez lambda funkcje: " << endl;
        for (auto txt : outS1)
            cout << txt << endl;
        cout << endl;
        
        vector<string> outS2(inS.size()); //bo wektor wynikowy ma być zainicjowany pustymi łańcuchami do zadanej długości
        transform(inS.begin(), inS.end(), outS2.begin(), DuzeLiteryFun());
        cout << "Transformacja przez funktory: " << endl;
        for (auto txt : outS2)
            cout << txt << endl;
        cout << endl;
    }
    static void zadaniaZSzablonow() {
        /*przykładem prostego szablonu z STL jest pair.
        Zadanie: napisać własny szablon na trójki [gotowy, patrz szablon TTrojka i
        napisać konkretyzację dla typu int i string (osobno) a potem utworzyć
        w define.h strukturę TOsoba która będzie potem jeszcze wykorzystywana dalej */
        TTrojka<int> trojkaInt(1, 2, 3);
        TTrojka<string> trojkaString("Ala", "ma", "kota");
        cout << trojkaInt.getElement(2) << " - tu powinna byc dwojka\n";
        cout << trojkaString.getElement(2) << " - tu powinno byc slowo <<ma>>\n";
        //czy konkretyzacją szablonu może być kolejna konkretyzacja?
        //tak, można, np:
        TTrojka<TTrojka<int>> trojkaTrojek = { {1,2,3}, {4,5,6}, {7,8,9} };
        /* bardziej formalnie można uruchomić konstruktory ,,zagnieżdżone'' w ten sposób,
        * ale jest on niemiłosiernie rozwlekły:
        TTrojka<TTrojka<int>> trojkaTrojek(TTrojka<int>(1,2,3), TTrojka<int>(4,5,6), TTrojka<int>(7,8,9) );
        */
        cout << trojkaTrojek.getElement(2).getElement(2) << "- tu powinna byc cyfra 5\n";
    }
};

int main()
{
    for (;;) {
        TMenu* mnu = new TMenu();
        mnu->addAll(7, "Testy kolekcji", "Wskazniki",
            "Zadania z kolekcji STL",
            "Zadania z wypisywania elementow kolekcji (z uzyciem lambda funkcji)",
            "Zadania z wypisywania elementow kolekcji (z uzyciem funktorow)",
            "Zadania z modyfikacji elementow kolekcji (z uzyciem funktorow)",
            "Zadania z szablonów"
        );
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
        case 4:
            Zadania::zadaniaZDzialanNaKolekcjach();
            break;
        case 5:
            Zadania::zadaniaZDzialanNaKolekcjachFunktory();
            break;
        case 6:
            Zadania::zadaniaZModyfikacjiKolekcjiFunktory();
            break;
        case 7:
            Zadania::zadaniaZSzablonow();
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
