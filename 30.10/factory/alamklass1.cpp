#include <iostream>
using namespace std;

class Kilpkonn {

    int x;

    public:
        Kilpkonn(int x) {
            this->x = x; 
        }
        int getY() {
            return y;
        }

};

class AlamKilpkonn : public Kilpkonn {
    int y;
    public:
        AlamKilpkonn(int x, int y) : Kilpkonn(x) {
            this->y = y;
        }
        int getY() {
            return y;
        }

        void edasi() {
            x++;
        }

};

int main() {
    AlamKilpkonn k1(3, 5);
    k1.edasi();

    cout << k1.getX() << k1.getY() << endl;
}

