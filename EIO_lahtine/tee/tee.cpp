#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double A, B, C, D;

    cin >> A >> B >> C >> D;

    // toa temp - 22 c
    // aeg      - 1 tund

    // 1. soojas hoidmine
    // c * aeg minutites
    cout << C * 60 << endl;

    // 2. uuesti kuumutamine

    // jahtumise sirge ja keemise sirge ristumse punkt
    double temp = (3600 / (B + 60 / D)) * A;
    if (temp/A > 78) {
        // Siis kui jahtub täielikult
        // 100 - 22 = 78 -> 78 * A
        cout << 78 * A << endl;
    } else {
        // Siis kui ei jahtu täielikult
        cout << temp << endl;
    }

}