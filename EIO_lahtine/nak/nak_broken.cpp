#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, Q, L, R, teineRida;
	cin >> N >> Q;

	vector<int> vanus(N);

	for (int i = 0; i < N; i++) {
		cin >> teineRida;
		vanus[i] = teineRida;
	}

    for (int i = 0; i < Q; i++) {
        cin >> L >> R;
        int range = R - L;

		nth_element(
            vanus.begin() + L,
            vanus.begin() + min(10, range),
            vanus.begin() + range
        );

        cout << vanus[min(10, range)];

        if (i != Q - 1) {
            cout << "\n";
        }
    }

}
