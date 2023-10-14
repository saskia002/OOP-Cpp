#include <iostream>

using namespace std;

int main() {

	string avaldis;
	int A, B;
	cin >> A >> B;

	if(A < -1 || A > 1) {
		avaldis.append(to_string(A) + "x");
	} else if (A == 1) {
		avaldis.append("x");
	} else if (A == -1) {
		avaldis.append("-x");
	}

	if(A == 0 && B == 0) {
		avaldis = "0";
	}

	if (A == 0) {
		avaldis = to_string(B);
	} else {
		if (B > 0) {
			avaldis.append("+" + to_string(B));
		} else if (B < 0) {
			avaldis.append(to_string(B));
		}
	}


	cout << avaldis << endl;
}