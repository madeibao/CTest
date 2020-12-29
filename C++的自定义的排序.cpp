
// C++实现的字典一个内容的多条件的排序。
// 

查找和排序

题目：输入任意（用户，成绩）序列，可以获得成绩从高到低或从低到高的排列,相同成绩
都按先录入排列在前的规则处理。

示例：
jack      70
peter     96
Tom       70
smith     67

从高到低  成绩
peter     96
jack      70
Tom       70
smith     67

从低到高

smith     67

jack      70
Tom      70
peter     96



3
0
fang 90
yang 50
ning 70


//-----------------------------------------------------------------------------------

fang 90
ning 70
yang 50



#include<iostream>
#include<bits/stdc++.h>

using namespace std;


struct Student {
	int score;
	int order;
	char name[20];
};

bool Ascend(Student A, Student B) {
	if (A.score == B.score) {
		return A.order <B.order;
	}
	else {
		return A.score < B.score;
	}
}

bool Descend(Student A, Student B) {
	if(A.score==B.score) {
		return A.order< B.order;
	}
	else {
		return A.score>B.score;
	}
}


int main(int argc, char *argv[]) {

	int m,type;
	while(cin>>m>>type)  {
		Student nums[m];
		for(int i=0; i<m;i++) {
			cin>>nums[i].name;
			cin>>nums[i].score;
			nums[i].order = i;
		}

		if(type ==0) {
			sort(nums, nums+m,Descend);
		}
		else {
			sort(nums, nums+m,Ascend);
		}

		for(int i=0; i<nums;i++) {
			cout<<nums[i].name<<" "<<nums[i].score<<endl;
		}
	}

	return 0;
}