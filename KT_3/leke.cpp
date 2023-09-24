#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct SpaceShipMap {
	int x;
	int y;
	int z;
	int wrt;
	string door;

	SpaceShipMap(int x, int y, int z, string door) : x(x), y(y), z(z), door(door), wrt(0) {}
	SpaceShipMap() {}
};

void simAirLeak(int x, int y, int z, vector<SpaceShipMap> &spaceShip, ofstream& outFile);
vector<SpaceShipMap> findNaaber(int x, int y, int z, const vector<SpaceShipMap>& spaceShip);
void outputResult(const SpaceShipMap& result, ofstream& outFile);


int main() {
	ifstream inpFile("./inp.txt");
	ofstream outFile("./out.txt");

	if (!inpFile) { cerr << "Unable to open file inp.txt" << endl; return 1; }
	if (!outFile) { cerr << "Unable to open file out.txt" << endl; return 1; }

	int U, x, y, z;
	string direction;

	inpFile >> U;
	vector<SpaceShipMap> spaceShip(U);

	for (int i = 0; i < U; i++) {
		inpFile >> x >> y >> z >> direction;
		spaceShip.push_back(SpaceShipMap(x, y, z, direction));
	}

	inpFile >> x >> y >> z;
	simAirLeak(x, y, z, spaceShip, outFile);
}

void simAirLeak(int x, int y, int z, vector<SpaceShipMap> &spaceShip, ofstream& outFile) {

	auto explosion = find_if(spaceShip.begin(), spaceShip.end(), [x, y, z](const SpaceShipMap &item) {
		return item.x == x && item.y == y && item.z == z;
	});
	if (explosion != spaceShip.end()) {
		explosion->wrt = 1;
		outFile << explosion->x << " " << explosion->y << " " << explosion->z << endl;
	}

	auto naaber = findNaaber(x + 1, y, z, spaceShip)[0];
	if (explosion->door == "X+" || naaber.door == "X-") {
		naaber.wrt = 1;
		outputResult(naaber, outFile);
		simAirLeak(naaber.x, naaber.y, naaber.z, spaceShip, outFile);
	}

	auto naaber1 = findNaaber(x - 1, y, z, spaceShip)[0];
	if (explosion->door == "X-" || naaber1.door == "X+") {
		naaber1.wrt = 1;
		outputResult(naaber1, outFile);
		simAirLeak(naaber1.x, naaber1.y, naaber1.z, spaceShip, outFile);
	}

	auto naaber2 = findNaaber(x, y + 1, z, spaceShip)[0];
	if (explosion->door == "Y+" || naaber2.door == "Y-") {
		naaber2.wrt = 1;
		outputResult(naaber2, outFile);
		simAirLeak(naaber2.x, naaber2.y, naaber2.z, spaceShip, outFile);
	}

	auto naaber3 = findNaaber(x, y - 1, z, spaceShip)[0];
	if (explosion->door == "Y-" || naaber3.door == "Y+") {
		naaber3.wrt = 1;
		outputResult(naaber3, outFile);
		simAirLeak(naaber3.x, naaber3.y, naaber3.z, spaceShip, outFile);
	}

	auto naaber4 = findNaaber(x, y, z + 1, spaceShip)[0];
	if (explosion->door == "Z+" || naaber4.door == "Z-") {
		naaber4.wrt = 1;
		outputResult(naaber4, outFile);
		simAirLeak(naaber4.x, naaber4.y, naaber4.z, spaceShip, outFile);
	}

	auto naaber5 = findNaaber(x, y, z - 1, spaceShip)[0];
	if (explosion->door == "Z-" || naaber5.door == "Z+") {
		naaber5.wrt = 1;
		outputResult(naaber5, outFile);
		simAirLeak(naaber5.x, naaber5.y, naaber5.z, spaceShip, outFile);
	}

}

vector<SpaceShipMap> findNaaber(int x, int y, int z, const vector<SpaceShipMap>& spaceShip) {
    vector<SpaceShipMap> result;
    copy_if(spaceShip.begin(), spaceShip.end(), back_inserter(result), [x, y, z](const SpaceShipMap& item) {
        return item.x == x && item.y == y && item.z == z;
    });
    return result;
}

void outputResult(const SpaceShipMap& result, ofstream& outFile) {
	if (result.wrt != 1) {
    	outFile << result.x << " " << result.y << " " << result.z << endl;
	}
}
