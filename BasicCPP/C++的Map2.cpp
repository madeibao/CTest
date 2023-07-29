
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool cmp(const pair<string, int> a, const pair<string, int> b) {
    return a.second > b.second;
}

int main(int argc, char** argv) {
	
	map<string,int>m;
	m["asas"]=18;
	m["ioio"]=90;
	m["cj"]=89;

	vector<pair<string,int>> v(m.begin(),m.end());
	sort(v.begin(),v.end(),cmp);

	for(int i=0;i<v.size();i++) {
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}

    return 0;
}


// 按照值来进行排序算法，降序排序算法