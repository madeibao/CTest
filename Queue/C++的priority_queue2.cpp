
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct fruit {
	string name;
	int prize;
} f1,f2,f3;

struct cmp {
	bool operator()(fruit f1, fruit f2) {
		return f1.prize > f2.prize;
	}
};

int main(int argc, char** argv) {

	priority_queue<fruit, vector<fruit>, cmp> queue;

	f1.name = "桃子";
	f1.prize = 3;

	f2.name = "梨子";
	f2.prize = 4;

	f3.name = "苹果";
	f3.prize = 1;

	queue.push(f1);
	queue.push(f2);
	queue.push(f3);

	cout<<queue.top().name<<" "<<queue.top().prize<<endl;
	return 0;
}
