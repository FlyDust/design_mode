//单例模式（Singleton Pattern）

#include <iostream>
#include <pthread.h>
using namespace std;

class Singleton {
private:
	static Singleton *singleton;
	static pthread_mutex_t mutex; //用于保证懒汉的线程安全
	Singleton();
	~Singleton();
public:
	static Singleton* getInstance();
};
//饿汉模式
/*Singleton* Singleton::singleton = new Singleton;
  Singleton* Singleton::getInstance() {
	return singleton;
  }

Singleton* Singleton::singleton = NULL;
pthread_mutex_t Singleton::mutex;

//懒汉模式，非线程安全
/*
Singleton::Singleton() {}
Singleton::~Singleton() {}
Singleton* Singleton::getInstance() {
	if(singleton == NULL) {
		singleton = new Singleton();
	}
	return singleton;
}*/

//懒汉模式，线程安全
Singleton::Singleton() {
	pthread_mutex_init(&mutex, NULL);
}
Singleton::~Singleton() {
	pthread_mutex_destroy(&mutex);
}
Singleton* Singleton::getInstance() {
	if(singleton == NULL) {
		pthread_mutex_lock(&mutex);
		if(singleton == NULL) {
			singleton = new Singleton();
		}
		pthread_mutex_unlock(&mutex);
	}
	return singleton;
}
