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
    void setStrategy(unique_ptr<ArvutusStrateegia> strat_)  {
    }
    void strategy()  { if (strat) strat->arvuta(); }
};
