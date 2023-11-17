

//-----------------------------------------------------------------------------
// 并查集的通用的模板

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Djset {
public:
	int count;
	vector<int> parent;
	vector<int> rank;
	Djset(int n):count(n) {
		for(int i=0;i<n;i++) {
			parent.push_back(i);
			rank.push_back(0);
		}
	}

	// 查找父亲节点

	int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }


    // 按照秩合并。
	void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) {
            if (rank[rx] < rank[ry]) {
                swap(rx, ry);
            }
            parent[ry] = rx;
            count--;
            if (rank[rx] == rank[ry]) {
            	rank[rx] += 1;
            }
        }
    }

};


int main() {


	return 0;
}
