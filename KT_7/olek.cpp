#include <iostream>

using namespace std;

// Forward declarations
class Olek;
class OlekTellimusKohaleToimetatud;
class OlekTellimusValmis;

class Tellimus;

class Olek {
public:
    virtual void olek() = 0;
};

class OlekTellimusLoodud : public Olek {
public:
    void olek() override {
        cout << "Tellimus loodud" << endl;
    }
};

class OlekTellimusTootmises : public Olek {
public:
    void olek() override {
        cout << "Tellimus tootmises" << endl;
    }
};

class OlekTellimusValmis : public Olek {
public:
    void olek() override {
        cout << "Tellimus valmis" << endl;
        //auto o1 = new OlekTellimusKohaleToimetatud();
        //o1->olek();
    }
};

class OlekTellimusKohaleToimetatud : public Olek {
public:
    void olek() override {
        cout << "Tellimus kohale toimetatud" << endl;
    }
};

class TellimuseOlek {
public:
    Tellimus* tellimus;
    Olek* olek;

    TellimuseOlek(Tellimus* tellimus);
    void makstud();
};

class Tellimus {
public:
    int summa;
    TellimuseOlek* tellimuseOlek;

    Tellimus(int summa);
    void lisaMakse(int summa);
};

// Implementations

Tellimus::Tellimus(int summa) {
    this->summa = summa;
    this->tellimuseOlek = new TellimuseOlek(this);
}

void Tellimus::lisaMakse(int summa) {
    cout << "Makse lisatud" << endl;
    this->summa += summa;
}

TellimuseOlek::TellimuseOlek(Tellimus* tellimus) {
    this->olek = new OlekTellimusLoodud();
    this->olek->olek();
    this->tellimus = tellimus;
}

void TellimuseOlek::makstud() {
    this->olek = new OlekTellimusTootmises();
    this->olek->olek();
	this->olek = new OlekTellimusValmis();
	this->olek->olek();
	this->olek = new OlekTellimusKohaleToimetatud();
	this->olek->olek();
}

int main() {
    Tellimus tellimus(100);
    tellimus.lisaMakse(50);
    tellimus.tellimuseOlek->makstud();

    return 0;
}
