#include <iostream>
using namespace std;

class Kilpkonn {

    int x, y;

    public:
        Kilpkonn(int x, int y) {
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

};

int main() {
    Kilpkonn k1(3, 5);
    k1.edasi();

    Kilpkonn k2(13, 5);

    Kilpkonn k3 = k1;
    k3.edasi();

    cout << k1.getX() << k1.getY() << endl;
    cout << k2.getX() << k2.getY() << endl;
    cout << k3.getX() << k3.getY() << endl;
    cout << k1.getX() << k1.getY() << endl;
}

