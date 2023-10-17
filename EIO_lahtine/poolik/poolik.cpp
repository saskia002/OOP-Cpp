#include <bits/stdc++.h>

using namespace std;

string N1 = "";
string N2 = "";
int indexN1 = 0, indexN2 = 0;
string output = "";

void fixSentenceN1() {
    if (N1[indexN1] == 'n' && N1[indexN1 + 1] == 'd') {
        output += "nd";
        indexN1 += 2;
        return;
    }

    if (N1[indexN1] != ' ') {
        output += N1[indexN1];
        indexN1++;
        return;
    }

    if (N1[indexN1] == ' ' && N1[indexN1 + 1] == ' ') {
        indexN1 += 1;
        if (N2[indexN2] == ' ') {
            indexN2++;
        }
        while (N2[indexN2] != ' ') {
            output += N2[indexN2];
            indexN2++;
        }

        if (indexN1 < N1.length() - 1 && N1[indexN1] == 't' && N1[indexN1 + 1] == 'e') {
            output += "te";
            indexN1 += 2;
        }
        return;
    }

    if (indexN1 < N1.length() - 1 && N1[indexN1] == 't' && N1[indexN1 + 1] == 'e') {
        output += "te";
        indexN1 += 2;
    }
}


void fixSentenceN2() {

	if (N2[indexN2] == 'e' && N2[indexN2 + 1] == 'i') {
		output += "ei";
		indexN2 += 2;
		return;
	}

	if (N2[indexN2] != ' ') {
		output += N2[indexN2];
		indexN2++;
		return;
	}

}

int main() {

	ifstream inpFile("./input_001.txt");
	ofstream outFile("./output_001.txt");

    getline(inpFile, N1);
    getline(inpFile, N2);



	int prevLetter = 0;

    while (indexN1 < N1.length()) {
		//cout << "index: " << prevLetter << " " << indexN1 << " " << indexN2 << " - " << output << ", " << N1[indexN1] << " " << N2[indexN2] << endl;

		if (N1[indexN1] == N2[indexN2]) {
			output += N1[indexN1];
			indexN1++;
			indexN2++;
		}

		if(prevLetter == 0) {
			fixSentenceN1();
		}
		if(prevLetter == 1) {
			fixSentenceN2();
		}
		prevLetter == 1 ? prevLetter = 0 : prevLetter = 1;
    }

    outFile << output << endl;

}
