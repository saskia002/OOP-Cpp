#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, Q, L, R, teineRida;
	cin >> N >> Q;

	vector<int> vanus(N);
	vanus.reserve(N);

	for (int i = 0; i < N; i++) {
		cin >> vanus[i];
	}

    for (int i = 0; i < Q; i++) {
        cin >> L >> R;
        int range = R - L + 1;

        vector<int*> j2rjekordVanused(range);
		j2rjekordVanused.reserve(range);

        for (int j = 0; j < range; j++) {
            j2rjekordVanused[j] = &vanus[j + L];
        }

        nth_element(
			j2rjekordVanused.begin(),
			j2rjekordVanused.begin() + min(10, range - 1),
			j2rjekordVanused.begin() + range,
			[](int* a, int* b) { return *a < *b; }
			);
        cout << *j2rjekordVanused[min(10, range - 1)];

        if (i != Q - 1) {
            cout << "\n";
        }
    }

}
