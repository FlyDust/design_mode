//适配器模式（Adapter Pattern）
//将一个类的接口转换成客户希望的另外一个接口，使得原本由于接口不兼容而不能一起工作的那些类可以一起工作

#include <iostream>
using namespace std;

class Deque {
public:
	void push_back(int x) {
		cout << "Deque push_back()" << endl;
	}
	void pop_back() {
		cout << "Deque pop_back()" << endl;
	}
	void push_front(int x) {
		cout << "Deque push_front()" << endl;
	}
	void pop_front() {
		cout << "Deque pop_front()" << endl;
	}
};

class Sequence {
public:
	virtual void push(int x) = 0;
	virtual void pop() = 0;
};

class Stack: public Sequence {
private:
	Deque deque;
public:
	void push(int x) {
		deque.push_back(x);
	}
	void pop() {
		deque.pop_back();
	}
};

class Queue: public Sequence {
private:
	Deque deque;
public:
	void push(int x) {
		deque.push_back(x);
	}
	void pop() {
		deque.pop_front();
	}
};
