#include <iostream>
using namespace std;

class Pig {
public:
	virtual void show() = 0;
	virtual ~Pig() {}
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

class Dog {
public:
	virtual void show() = 0;
};

class DogA: public Dog {
public:
	void show() {
		cout << "I am a dog in A." << endl;
	}
};

class DogB: public Dog {
public:
	void show() {
		cout << "I am a dog in B." << endl;
	}
};

class AbstractFactory {
public:
	virtual Pig* createPig() = 0;
	virtual Dog* createDog() = 0;
};

class FactoryA: public AbstractFactory {
public:
	Pig* createPig() {
		return new PigA();
	}
	Dog* createDog() {
		return new DogA();
	}
};

class FactoryB: public AbstractFactory {
public:
	Pig* createPig() {
		return new PigB();
	}
	Dog* createDog() {
		return new DogB();
	}
};
