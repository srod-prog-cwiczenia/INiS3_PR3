#pragma once
/*Zadanie: przygotowaæ klasê abstrakcyjn¹ (=interface) 
dla TMenu.
Przypomnienie: Klasa abstrakcyjna to klasa która nie mo¿e mieæ instancji */
class TMenuAbs {  //to jest klasa abstrakcyjna (bo zawiera 
	//konstrukcje postaci: virtual ... = 0;
public: 
	virtual void addAll(int ilePar, ...) = 0; 
	virtual unsigned int wybierz() = 0;
	TMenuAbs() {};
	virtual ~TMenuAbs() {};
	/*
	  implementacja tego interfejsu powinna funkcjonowaæ tak:
    	TMenu* mnu = new TMenu();
		mnu->addAll(2, "Opcja 1", "Opcja 2"); 
		  (automatyczna numeracja + 0. Wyjscie).
		auto opcja = mnu->wybierz();
		delete mnu;
	*/
};
class TMenu: public TMenuAbs
{
private:
	vector<string> tabItemsV;
public:
	void add(const string &item);
	void addAll(int ilePar, ...);
	unsigned int wybierz();
	TMenu();
	~TMenu();
};

