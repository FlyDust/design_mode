//策略模式
//定义一系列算法，把它们一个个封装起来，并且使它们可以相互替换

#include <iostream>
using namespace std;

class SortAlgorithm {
public:
	virtual void sort() = 0;
};

class QuickSort: public SortAlgorithm {
public:
	void sort() {
		cout << "Quick sort." << endl;
	}
};

class HeapSort: public SortAlgorithm {
public:
	void sort() {
		cout << "Heap sort." << endl;
	}
};

//方法一
class MyArray1 {
private:
	SortAlgorithm *_s;
public:
	MyArray1(SortAlgorithm *s): _s(s) {}
	~MyArray1() { delete _s; _s = NULL;}
	void sort() {
		_s->sort();
	}
};

//方法二
enum STYPE {SQUICK, SHEAP};
class MyArray2 {
private:
	SortAlgorithm *_s;
public:
	MyArray2(enum STYPE tag) {
		if(tag == SQUICK)
			_s = new QuickSort();
		else if(tag == SHEAP)
			_s = new HeapSort();
		else
			_s = NULL;
	}
	~MyArray2() {
		delete _s;
		_s = NULL;
	}
	void sort() {
		if(_s) _s->sort();
	}
};

//方法3
template <typename SA>
class MyArray3 {
private:
	SA _s;
public:
	MyArray3() {}
	~MyArray3() {}
	void sort() {
		_s.sort();
	}
};
