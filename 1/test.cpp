#include <iostream>
using namespace std;

int main(void) {
	/*
	// Terve!
	cout << "Tervist" << endl;
  
	// IO
	int a, b;
	cout << "Sisesta üks tore arv: ";
	cin >> a;
	cout << "Sisesta üks teine tore arv: ";
	cin >> b;
	cout << "Summa on: " << (a + b) << endl;
	
	// IO char length
	cahr nimi[20];
	cout << "Mis on sinu nimi?: ";
	cin.getLime(nimi, 20); 
	cout << "Tere, " << endl;
	cout << "Mis on su kutsa nimi?: ";
	cin.getLime(nimi, 20); 
	cout << "Hei, " << nimi << endl;
	
	
	// IO text 
	int kogus;
	cin >> kogus;
	string nimi;
	
	for(int i=0; i<kogus; i++) {
		cin >> nimi;
		cout << "Tere, " << nimi << "!\n";
	}
	
	
	// masiiv
	int cnt;
	cin >> cnt;
	string* strPpl = new string[cnt];
	
	for(int i=0; i<cnt; i++) {
		cin >> strPpl[i];
	}
	
	for(int i=cnt-1; i>=0; i--) {
		cout << "Tere, " << strPpl[i] << "!\n"; 
	}
	*/
	
	union Juku {
		int mass;
		int pikkus;
	};
	
	Juku juku;
	
	juku.mass = 12;
	juku.pikkus = 2;
	cout << juku.mass << " " << juku.pikkus << endl;
	
	
	return 0;
}