

#include<bits/stdc++.h>
using namespace std;
//对于键是结构体的自定义排序

typedef struct node{
	int score;
	string name;
	bool operator <(const node &s)const{
		if(score!=s.score)return score>s.score;
        return name>s.name;
	}
} node;
 
int main()
{
	map<node,int>m;
	node u;
	u.name="abc";
	u.score=99;
	m[u]=12;


	u.name="bcd";
	u.score=99;
	m[u]=13;


	u.name="bbb";
	u.score=100;
	m[u]=14;

	u.name="yuy";
	u.score=15;
	m[u]=6666;

	map<node,int>::iterator it;
	for(it=m.begin();it!=m.end();it++){
		cout<<"成绩="<<it->first.score<<" 名字="<<it->first.name<<" 学号="<<it->second<<endl;
	}
	return 0;
}