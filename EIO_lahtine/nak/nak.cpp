#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, Q, L, R, teineRida;
	cin >> N >> Q;

	vector<int> vanus(N);

	for (int i = 0; i++ < N;) {
		cin >> teineRida;
		vanus[i] = teineRida;
	}

	for (int i = 0; i++ < Q;) {
		cin >> L >> R;

		vector<int*> j2rjekordVanused(R-L+1);

		for (int j = 0; j < R-L+1; j++) {
			j2rjekordVanused[i] = &vanus[j + L];
		}

		int minVal = min(10, R-L);

		nth_element(
			j2rjekordVanused.begin(),
			j2rjekordVanused.begin() + minVal,
			j2rjekordVanused.begin() + R-L+1,
			[](int* a, int* b) { return *a < *b; }
		);

		//cout << j2rjekordVanused[minVal] << "\n";

	}
}
