//原型模式(Prototype Pattern)
//用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象


#include <iostream>
#include <cstring>
using namespace std;

class Resume {
protected:
	char *name;
public:
	virtual Resume* clone() = 0;
	virtual ~Resume() {}
};

class ResumeA: public Resume {
public:
	ResumeA(char *a);
	ResumeA(const ResumeA& a);
	~ResumeA();
	ResumeA* clone();
};

ResumeA::ResumeA(char *a) {
	if(a == NULL) {
		name = new char[1];
		name[0] = '\0';
	} else {
		name = new char[strlen(a)+1];
		name[strlen(a)] = '\0';
	}
}

ResumeA::ResumeA(const ResumeA& a) {
	if(a.name == NULL) {
		name = new char[1];
		name[0] = '\0';
	} else {
		name = new char[strlen(a.name)+1];
		name[strlen(a.name)] = '\0';
	}
}

ResumeA::~ResumeA() {
	delete []name;
}

ResumeA* ResumeA::clone() {
	return new ResumeA(*this);
}
