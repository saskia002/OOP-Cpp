#include <iostream>

using namespace std;

int main() {
	int kanded = 0;
	int kulutatud = 0;
	int voidetud = 0;
	int kokkuKulu = 0;
	int kokkuVoit = 0;
	int maxKaotusPaev = 0;
	int kaotusSumma = 0;
	int p1 = 0;
	int p2 = 0;
	int s1 = 0;
	int s2 = 0;
	cin >> kanded;

	for(int i=1; i<=kanded; i++) {
		cin >> kulutatud >> voidetud;

		kokkuKulu += kulutatud;
		kokkuVoit += voidetud;

		cout << "asd " << kokkuKulu << " " << kokkuVoit << endl;



		if (kokkuKulu >= kokkuVoit && ) {
			cout << "asd " << s2 << endl;
			if (p1 == 0) p1 = i;
			p2 = i;
			s2 += voidetud;
			s1 += kulutatud;

		}

		if (kulutatud > voidetud) {
			if (kulutatud - voidetud > kaotusSumma) {
				maxKaotusPaev = i;
				kaotusSumma = kulutatud - voidetud;
			}

			if (kokkuVoit >= kokkuKulu) {
				p1 = 0;
				p2 = 0;
				s1 = 0;
			}

		}



	}

	if (kokkuKulu > kokkuVoit) {
		cout << "MIINUSES" << endl;
	} else if (kokkuKulu < kokkuVoit) {
		cout << "PLUSSIS" << endl;
	} else if (kokkuKulu == kokkuVoit) {
		cout << "NULLIS" << endl;
	} else {
		cout << "EI TEA" << endl;
	}

	cout << maxKaotusPaev << " " << kaotusSumma << endl;
	cout << p1 << " " << p2 << " " << s1 << " " << s2 << endl;
}