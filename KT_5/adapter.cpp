#include <iostream>
#include <string>

using namespace std;

class Plug {
public:
    virtual void plugIntoOutlet() = 0;
};

class Socket {
public:
    virtual void plugIn() = 0;
};



class UsPlug : public Plug {
public:
    void plugIntoOutlet() {
        cout << "Plugging into a US outlet." << endl;
    }
};

class EuSocket : public Socket {
public:
    virtual void plugIn() = 0;
};

class EuSocketAdapter : public EuSocket {
private:
    Plug* plug;

public:
    EuSocketAdapter(Plug* inpPlug) : plug(inpPlug) {}

    void plugIn() { //override {
        if (plug) {
            plug->plugIntoOutlet();
            cout << "Adapter: Adapted to fit EU outlet." << endl;
        } else {
            cerr << "Adapter: Cannot adapt, US plug is not connected." << endl;
        }
    }
};

int main() {
    UsPlug usPlug;
    EuSocketAdapter adapter(&usPlug);
    adapter.plugIn();

    return 0;
}
