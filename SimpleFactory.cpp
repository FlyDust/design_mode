//简单工厂模式

#include <iostream>
using namespace std;

enum CTYPE {CPIGA, CPIGB};

class Pig {
public:
	virtual void show() = 0;
};

//A家养殖场的猪
class PigA: public Pig {
public:
	void show() {
		cout << "I am a pig in A." << endl;
	}
};

//B家养殖场的猪
class PigB: public Pig {
public:
	void show() {
		cout << "I am a pig in B." << endl;
	}
};


//唯一工厂
class SimpleFactory {
public:
	Pig* createPig(enum CTYPE type) {
		if(type == CPIGA) {
			return new PigA();
		} else if(type == CPIGB) {
			return new PigB();
		}
		return NULL;
	}
};
