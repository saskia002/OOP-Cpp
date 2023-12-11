#include <iostream>
using namespace std;


class Isik {
    string eesnimi="", perekonnanimi="";

    public:
        Isik* eesnimega(string uusEesnimi){
            this->eesnimi = uusEesnimi;
            return this;
        }
        Isik* perekonnanimega(string uusperekonnanimi){
            this->perekonnanimi = uusperekonnanimi;
            return this;
        }
        string tekstina() {
            string vastus = "";
            if (eesnimi != "") { 
                vastus += eesnimi + " ";
            }
            if (perekonnanimi != "") { 
                vastus += perekonnanimi;
            }

            return vastus;
        }
};

int main() {
    Isik *i1 = (new Isik())->eesnimega("Juku")->perekonnanimega("Kaalikas");

    cout << i1->tekstina() << endl;

}

