
#include<iostream>
#include<bits/stdc++.h>	

using namespace std;

// 用来统计一个数字中的1的出现的次数。
int sum2(int a) {
	vector<int> res;
	while (a) {
		int temp = a%2;
		res.push_back(temp);
		a /= 2;
	}

	// 这个区间范围内的数字1的个数，第三个参数代表的是统计某一个数字。
	return count(res.begin(), res.end(), 1);
}

vector<int> count2(int b) {
	
	vector<int> res;
	while (b) {
		int temp = b%2;
		res.push_back(temp);
		b /= 2;
	}
	return res;
}

int main(int argc, char* argv[]) {


	vector<int> self;
	vector<vector<int>> temp;
	multimap<int,int> m;
	vector<int> res;

	int T;
	int num;
	vector<int> vec;
	cout<<"请输入一个数字个数"<<endl;
	cin>>T;
	cout<<endl;
	while(T>0) {
		cin>>num;

		for(int i =num;i>0;i--)  {
			if(count2(i).size()==count2(num).size()) {
				m.insert(pair<int,int>(sum2(i),i));
			}
		}

		multimap<int,int>::iterator itl = --m.end();

		int tmp = itl->second;
		for(auto it= m.rbegin();it!= m.rend();it++) {
			if(tmp==it->second) {
				tmp = it->second;
			}
			else {
				res.push_back(tmp);
				break;
			}
		}
		m.clear();
		T-=1;

	}

	cout<<endl;
	cout<<"下面是输出结果值"<<endl;
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<endl;
	}
	cout<<<endl;
	system("pause");
	return 0;

}



























