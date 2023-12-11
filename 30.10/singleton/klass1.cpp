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

};

int main() {

    Kilpkonn k1(3, 5);

    cout << k1.getX() << k1.getY() << endl;

}

