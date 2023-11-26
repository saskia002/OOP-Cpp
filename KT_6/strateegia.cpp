#include <iostream>
#include <string>
#include <memory>
#include <utility>

using namespace std;

class ArvutusStrateegia {
public:
    virtual void arvuta() = 0;
    virtual ~ArvutusStrateegia() {}
};

class Context {
    unique_ptr<ArvutusStrateegia> strat{};
public:
    void setStrateegia(unique_ptr<ArvutusStrateegia> strat_)  {
        strat = move(strat_);
    }
    void strateegia()  { if (strat) strat->arvuta(); }
};

class Liitmine : public ArvutusStrateegia {
public:
    void arvuta() override { cout << "Liitmine" << endl; }
};

class Lahutamine : public ArvutusStrateegia {
public:
    void arvuta() override { cout << "Lahutamine" << endl; }
};

class Korrutamine : public ArvutusStrateegia {
public:
    void arvuta() override { cout << "Korrutamine" << endl; }
};

class Jagamine : public ArvutusStrateegia {
public:
    void arvuta() override { cout << "Jagamine" << endl; }
};

int main() {
    Context context;
    context.setStrateegia(make_unique<Liitmine>());
    context.strateegia();
    context.setStrateegia(make_unique<Lahutamine>());
    context.strateegia();
    context.setStrateegia(make_unique<Korrutamine>());
    context.strateegia();
    context.setStrateegia(make_unique<Jagamine>());
    context.strateegia();
}