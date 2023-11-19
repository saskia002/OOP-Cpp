#include <iostream>

using namespace std;

#define stringify( name ) #name

enum chargerPort {
	USB_C,
	Lightning,
	MicroUSB,
	Other
};

class Phone {
	protected:
		string name;
		chargerPort port;
	public:
		virtual ~Phone() {}
		virtual void print() = 0;
};

class iPhone : public Phone {
	public:
		iPhone() : Phone() {
			name = "iPhone";
			port = chargerPort::Lightning;
		}
		void print() {
			cout << name << " " << port << "\n";
		}
};

class Samsung : public Phone {
	public:
		Samsung() : Phone() {
			name = "Samsung";
			port = USB_C;
		}
		void print() {
			cout << name << " " << port << "\n";
		}
};

class PhoneFactory {
	public:
		Phone* createPhone(string name) {
			if (name == "iPhone") {
				return new iPhone();
			} else if (name == "Samsung") {
				return new Samsung();
			} else {
				return NULL;
			}
		}
};

int main() {
	PhoneFactory* factory = new PhoneFactory();
	//Phone* phone = factory->createPhone("iPhone");

	factory->createPhone("iPhone")->print();
	factory->createPhone("Samsung")->print();
}
