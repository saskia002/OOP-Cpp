#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, Q, L, R, teineRida;
	cin >> N >> Q;

	vector<int> vanus(N);
	vector<int> j2rjekordVanused(N);

	for (int i = 0; i < N; i++) {
		cin >> vanus[i];
	}

	for (int i = 0; i < Q; i++) {
		cin >> L >> R;
		int range = R - L + 1;

        for (int j = L; j <= R; j++) {
			j2rjekordVanused[j-L] = vanus[j];
		}

		nth_element(j2rjekordVanused.begin(), j2rjekordVanused.begin() + min(10, range - 1), j2rjekordVanused.begin() + range);
        cout << j2rjekordVanused[min(10, range - 1)];

		if (i != Q-1)  {
			cout << "\n";
		}

	}

}
