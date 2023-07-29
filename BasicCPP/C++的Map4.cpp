#include<bits/stdc++.h>
using namespace std;
//按照键是结构体的排序
typedef struct{
	string name;
	int score;
}node;

struct rule{
	bool operator()(node a,node b){
		if(a.score==b.score){
			return a.name>b.name;
		}
		return a.score>b.score;
	}
	//排序规则是按照成绩大的在前面，相同按照名字降序
};

int main(int argc, char* argv[]) {
	
	node stu;
	map<node,int,rule>m;
	stu.name="abc";
	stu.score=88;
	m[stu]=1212;
	stu.name="acd";
	stu.score=88;
	m[stu]=1213;
	stu.name="bcbc";
	stu.score=100;
	m[stu]=1214;
	stu.name="zzzzzz";
	stu.score=1000;
	m[stu]=8989;


	map<node,int,rule>::iterator it;
	for(it=m.begin();it!=m.end();it++){
		cout<<"名字="<<it->first.name<<" 成绩="<<it->first.score<<" 学号="<<it->second<<endl;
	}
	return 0;
}