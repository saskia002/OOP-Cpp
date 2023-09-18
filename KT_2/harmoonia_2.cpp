#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream inpFile("./hargsis.txt");
	ofstream outFile("./hargval.txt");

	if (!inpFile) {
		cerr << "Unable to open file hargsis.txt" << endl;
		return 1;
	}
	if (!outFile) {
		cerr << "Unable to open file hargval.txt" << endl;
		return 1; // exit(1);
	}

	int N, K, pitch, found = 0; // nootide arv N ja häälte arv K, nooti kõrgus pitch semitonides
	inpFile >> N >> K;

	vector<int> current(K); // rea nootide kõrgused
	vector<int> prev(K); // eelmise rea nootide kõrgused

	for(int i = 0; i < N; i++) {
		for (int l = 0; l < K; l++) {inpFile >> current[l]; }

		for (int j = 0; j < K; j++) {
            for (int m = j+1; m < K; m++) {
                if (current[j] != prev[j] && current[m] != prev[m] &&
                    (prev[j]-prev[m]) % 12 == 7 &&
                    (current[j]-current[m]) % 12 == 7) {
                    found = 1;
					outFile << i << " " << j+1 << " " << m+1 << endl;
                }
            }
        }

		for (int o = 0; o < K; o++) { prev[o] = current[o]; }
	}

	if (found == 0) { outFile << "POLE" << endl; }

	inpFile.close();
	outFile.close();
}