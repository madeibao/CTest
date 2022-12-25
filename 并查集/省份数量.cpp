



/**

int findFather2(int x)
{
	int a = x;				//由于最后x要变成它的根节点的值，所以先备份它
	while (x != findFather(x))		
	{
		x = father[x];		
	}
	while (a != father[a])		//再用x初始值循环一遍
	{
		int z = a;			//由于a查找的过程又会被覆盖,每次用z来备份
		a = father[a];		//先将当前节点变为其父亲节点
		father[z] = x;		//再将刚刚的节点的父亲节点改为根节点的值
	}
}



*/

int findFather2(int x)
{
	int a = x;				//由于最后x要变成它的根节点的值，所以先备份它
	while (x != findFather(x))		
	{
		x = father[x];		
	}
	while (a != father[a])		//再用x初始值循环一遍
	{
		int z = a;			//由于a查找的过程又会被覆盖,每次用z来备份
		a = father[a];		//先将当前节点变为其父亲节点
		father[z] = x;		//再将刚刚的节点的父亲节点改为根节点的值
	}
}

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
	int father[210];
	int n ;

	// 并查集的初始化
	void init(int n) {
		for(int i=0;i<n;i++) {
			father[i] = i;
		}
	}

	// 查找父节点
	int find(int n) {
		if(n == father[n]) {
			return n;
		}
		else {
			father[n] = find(father[n]);
		}
		return father[n];
	}

	// 两个归并到一起

	void join(int u, int v) {
		int a = find(u);
		int b = find(v);
		if(a==b) {
			return;
		}
		father[v] = u;
	}

	bool same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        init(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j]) join(i, j);
            }
        }
        // 此时已经并查集已经把边链接好了
        unordered_set<int> uset; // 容积有多少个没有链接的省份
        for (int i = 0; i < n; i++) {
            uset.insert(find(i));
        }
        return uset.size();
    }
};

int main(int argc, char** argv) {
	vector<vector<int> > isconnected = {{1,1,0},{1,1,0},{0,0,1}};
	Solution s2;
	cout<<s2.findCircleNum(isconnected)<<endl;
	return 0;
}
