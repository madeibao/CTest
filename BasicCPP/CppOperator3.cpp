
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Person {
public:
	int a;
	int b;
public:
	Person operator+(Person &p) {
		Person temp;
		temp.a = this->a+p.a;
		temp.b = this->b+p.b;
		return temp;
	}
};

int main(int argc, char **argv) {

	Person pa;
	pa.a = 10;
	pa.b = 20;

	Person pb;
	pb.a = 100;
	pb.b = 200;

	Person p3;
	p3 = pa + pb;

	cout<<p3.a<<" "<<p3.b<<endl;

	return 0;
}
