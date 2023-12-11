#include <bits/stdc++.h>
using namespace std;

class s6naVektor {
    vector<string> sonad;
    public:
        s6naVektor(string lause) {
            stringstream ss(lause);
            for(string abi=""; getline(ss, abi, ' '); ){
                sonad.push_back(abi);

            }
        }
        vector<string> kysiS6nad() {
            return sonad;
        }
};

class uurija {
    vector<string> sv;
    public:
        uurija(s6naVektor sv1) {
            sv = sv1.kysiS6nad();
        }
        int mituKordaEsineb(string s) {
            int esineb = 0;
            for (int i=0; i<sv.size(); i++) {
                if (sv[i] == s) {
                    esineb ++;
                }
            }
            return esineb;
        }
};

int main() {
    s6naVektor tt("JUKU JA MATI JA");
    vector<string> v1 = tt.kysiS6nad();
    
    for (int i = 0; i<v1.size(); i++) {
        cout << v1[i] << endl;
    }

    uurija u1(tt);
    cout << u1.mituKordaEsineb("JA") << endl;
}