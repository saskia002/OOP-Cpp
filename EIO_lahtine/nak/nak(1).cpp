#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ostringstream oss;

	int N, Q, L, R, teineRida;
	cin >> N >> Q;

	vector<int> vanus(N);
	vanus.reserve(N);

	for (int i = 0; i < N; i++) {
		cin >> teineRida;
		vanus[i] = teineRida;
	}

	for (int i = 0; i < Q; i++) {
		cin >> L >> R;
		vector<int> j2rjekordVanused(R-L+1);
		j2rjekordVanused.reserve(R-L+1);

        for (int j = L; j <= R; j++) {
			j2rjekordVanused[j-L] = vanus[j];
		}

	  	if (j2rjekordVanused.size() < 11) {
            nth_element(j2rjekordVanused.begin(), j2rjekordVanused.begin() + R - L, j2rjekordVanused.end());
            oss << j2rjekordVanused[R - L];
        } else {
            nth_element(j2rjekordVanused.begin(), j2rjekordVanused.begin() + 10, j2rjekordVanused.end());
            oss << j2rjekordVanused[10];
        }

		if (i != Q-1)  {
			oss << "\n";
		}

	}

    cout << oss.str() << endl;

}
