//建造者模式（Builder Pattern）
//将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示

#include <iostream>
using namespace std;

class Builder {
public:
	virtual void buildHead() {}
	virtual void buildLeg() {}
	virtual void buildArm() {}
};

class ThinBuilder: public Builder {
public:
	void buildHead() {
		cout << "Thin bulid head." << endl;
	}
	void buildLeg() {
		cout << "Thin build leg." << endl;
	}
	void buildArm() {
		cout << "Thin build arm." << endl;
	}
};

class FatBuilder: public Builder {
public:
	void buildHead() {
		cout << "Fat build head." << endl;
	}
	void buildLeg() {
		cout << "Fat build leg." << endl;
	}
	void buildArm() {
		cout << "Fat build arm." << endl;
	}
};

class Director {
private:
	Builder *m_builder;
public:
	Director(Builder *builder): m_builder(builder) {}
	void create() {
		m_builder->buildHead();
		m_builder->buildLeg();
		m_builder->buildArm();
	}
};

int main(int argc, char *argv[]) {
	ThinBuilder builder;
	Director director(&builder);
	director.create();
	return 0;
}
