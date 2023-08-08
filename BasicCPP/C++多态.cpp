

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Animal {
public:
	virtual void speak() {
		cout<<"动物在说话"<<endl;
	}

	void dospeak(Animal &animal) {
		animal.speak();
	}
};


//猫类
class Cat : public Animal {
public:
	void speak() {
		cout << "小猫在说话" << endl;
	}
};


//狗类
class Dog :public Animal {
public:
	void speak() {
		cout << "小狗在说话" << endl;
	}
};

void test01() {
	Cat cat;
	dospeak(cat);

	Dog dog;
	dospeak(dog);
}

int main() {
	test01();
	system("pause");
	return 0;
}