#include <iostream>
#include <cmath>

using namespace std;

int main() {

	//http://www.se16.info/js/cuboid.htm#SpiderFly
	// See on ant and honey probleemi põhjal tehtud ülessanne.

    int Xr, Yr, Zr;
    int Xs, Ys, Zs;
    int Xm, Ym, Zm;

    cin >> Xr >> Yr >> Zr;
    cin >> Xs >> Ys >> Zs;
    cin >> Xm >> Ym >> Zm;

    double distance = 0;

    // Flatten the cuboid into a rectangular shape
    Xr = min(Xr, abs(Xs - Xm));
    Yr = min(Yr, abs(Ys - Ym));
    Zr = min(Zr, abs(Zs - Zm));

    // Calculate the shortest path using Pythagoras
    distance = sqrt(Xr * Xr + Yr * Yr + Zr * Zr);

    cout << distance << endl;
}
