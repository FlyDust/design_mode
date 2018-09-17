#include <iostream>
using namespace std;

class Pig {
public:
	virtual void show() = 0;
};

class PigA: public Pig {
public:
	void show() {
		cout << "I am a pig in A." << endl;
	}
};

class PigB: public Pig {
public:
	void show() {
		cout << "I am a pig in B." << endl;
	}
};

class Factory {
public:
	virtual Pig* createPig() = 0;
};

class FactoryA: public Factory {
public:
	Pig* createPig() {
		return new PigA();
	}
};

class FactoryB: Factory {
public:
	Pig* createPig() {
		return new PigB();
	}
};
