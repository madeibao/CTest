

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
        vector<int> fathers;


        // 初始算法
		int find(int i) {
			while (fathers[i]!=i) {
				i = fathers[i];
			}
			return i;
		}

		// 优化算法
		int find2(int i) {

			int a = i;
			while (fathers[i]!=i) {
				i = fathers[i];
			}

			while (a!=fathers[a]) {
				int b = a;
				a = fathers[a];
				fathers[b] = i;
			}
			return i;
		}

		// 优化算法
		int find3(int v) {
		  if (fathers[v] != v ) {
		    // v 元素指向根节点
		    fathers[v] = find(fathers[v]); 
		  }
		  return fathers[v];
		}


		void uni(int i, int j) {

			int f1 = find3(i);
			int f2 = find3(j);
			fathers[f2] = f1;
		}

		int findCircleNum(vector<vector<int>> &M ) {

			int n = M.size();
			if(n==0) {
				return 0;
			}

			for(int i=0;i<n;i++) {
				fathers.push_back(i);
			}
			// 只需要遍历上半部分的表结构就行。
			for(int i=0;i<n-1;i++) {
				for(int j=i+1;j<n;j++) {
					if(M[i][j]==1) {
						uni(i,j);
					}
				}
			}

			for(int i=0;i<n;i++) {
//				cout<<fathers[i]<< " "<<endl;
			}
			int count =0;
			for(int i=0;i<n;i++) {
				if(fathers[i]==i) {
					count++;
				}
			}
			return count;
		}
};

int main(int argc, char** argv) {

    vector<vector<int>> nums = {{1,0,0},{0,1,0},{0,0,1}};
    Solution s;
    cout<<s.findCircleNum(nums)<<endl;
    return 0;
}
