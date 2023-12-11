#include <iostream>
using namespace std;

class Kilpkonn {
    
    int x, y;
    static Kilpkonn* ainuke;

    Kilpkonn(){}

    // Koopia konstruktor
    Kilpkonn(const Kilpkonn& obj) { }

    public:
        void setAsukoht(int x, int y) {
            this->x = x; 
            this->y = y;
        }

        int getX() {
            return x;
        }

        int getY() {
            return y;
        }

        void edasi() {
            x++;
        }

        static Kilpkonn* getInstance() {
            if (ainuke == NULL) {
                ainuke = new Kilpkonn();
            }
            return ainuke;
        }

};

Kilpkonn* Kilpkonn::ainuke = NULL;

int main() {
    Kilpkonn *k1 = Kilpkonn::getInstance();
    k1->setAsukoht(2, 10);
    k1->edasi();

    cout << k1->getX() << k1->getY() << endl;

    //Kilpkonn *k3 = k1;
    Kilpkonn *k3 = Kilpkonn::getInstance();
    k1->setAsukoht(10, 2);
    k3->edasi();

    cout << k3->getX() << k3->getY() << endl;
    cout << k1->getX() << k1->getY() << endl;

    // Kilpkonn k2 = *k3;
    // k2.edasi();

    // cout << k1->getX() << k1->getY() << endl;
    // cout << k2.getX() << k2.getY() << endl;
}

