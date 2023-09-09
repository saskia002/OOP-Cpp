#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ifstream inpFile("./vaipsis.txt");
	ofstream outFile("./vaipval.txt");

	if (!inpFile) {
		cerr << "Unable to open file vaipsis.txt" << endl;
		return 1;
	}
	if (!outFile) {
		cerr << "Unable to open file vaipval.txt" << endl;
		return 1; // exit(1);
	}

	// Line 1: carpet count (line count), y and x
	// Line 2+: N S W E carpet edge cordinates to wall

	/* Matrix (room):
		  x
		y 0 ----> j
		  |
		  |
		  V
		  i
	*/

	int x, y, count, area = 0;
	int N, S, W, E = 0;
	inpFile >> count >> y >> x;
	vector<vector<int>> room(x, vector<int>(y));

	for (int i = 0; i < count; i++) {
		inpFile >> N >> S >> W >> E;

		for (int i = 0; i < x-N-S; i++) {
			for (int j = 0; j < y-W-E; j++) {
				if (room[N+i][E+j] != 1) {
					room[N+i][E+j] = 1;
					area++;
				}
			}
		}

	}

	// Print Vector (room) to console
	cout << endl << "Vaipade pindala: " << area << endl;
    for (const vector<int>& row : room) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

	inpFile.close();
	outFile << area;
	outFile.close();
}