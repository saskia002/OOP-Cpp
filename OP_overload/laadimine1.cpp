#include <iostream>
#include <cmath>

using namespace std;

class Ajavahemik {
    int tunnid, minutid, sekundid;

    public:
        Ajavahemik(int t, int m, int s) {
            tunnid = t; minutid = m; sekundid = s;
        }

        void aegÕigeks() {
            if (this->minutid > 60) {
                this->tunnid += 1;
                this->minutid = abs(60 - this->minutid);
            }
            if (this->sekundid > 60) {
                this->minutid += 1;
                this->sekundid = 60 - this->sekundid;
            }
        }

        // Ajavahemik* operator+=(Ajavahemik& av) {
        //     this->minutid += av.minutid;
        //     this->sekundid += av.sekundid;
        //     this->tunnid += av.tunnid;
        //     return this;           
        // }
        // see parem veidi :)
        void operator+=(Ajavahemik& av) {
            minutid += av.minutid;
            sekundid += av.sekundid;
            tunnid += av.tunnid;  
            // aegÕigeks()         
        }

        Ajavahemik operator+(Ajavahemik& teine) {
            Ajavahemik a(tunnid + teine.tunnid, minutid+teine.minutid, sekundid+teine.sekundid);
            return a;
        }

        friend ostream& operator<<(ostream& os, const Ajavahemik& av) {
            cout << av.tunnid << ":" << av.minutid << ":" << av.sekundid;
            return os;
        }

        int& operator[](int nr) {
            if(nr == 0) { return tunnid; }
            if(nr == 1) { return minutid; }
            if(nr == 2) { return sekundid; }
            return tunnid;
            // return -1;
        }
};

int main() {
    Ajavahemik av(12,25,11);
    cout << av << "; " << av << endl;

    av[1]++;
    cout << av << "; " << endl;

    Ajavahemik av2(1,55,1);
    Ajavahemik a3 = av + av2;

    cout << a3 << endl;

    a3.aegÕigeks();

    cout << a3 << endl;

    a3 += av;

    cout << a3 << endl;

    cout << a3[1] << endl;
     cout << a3[12] << endl;
}