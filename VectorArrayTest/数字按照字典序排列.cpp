





// 给你一个整数 n ，按字典序返回范围 [1, n] 内所有整数。

// 你必须设计一个时间复杂度为 O(n) 且使用 O(1) 额外空间的算法。



#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {

        int cur = 1;
        vector<int> res;
        for(int i=0;i<n;i++) {
            res.push_back(cur);
            if(cur*10<=n) {
                cur*=10;
            }
            else {
                if(cur>=n) {
                    cur /=10;
                }
                cur+=1;
                while(cur%10==0) {
                    cur = cur/10;
                }
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {


	int n = 13;
	vector<int> res;
	Solution s2;
	res = s2.lexicalOrder(n);
	for(auto i:res) {
		cout<<i<<" "<<endl;
	}
	return 0;
}




// 1 10 11 12 13 2 3 4 5 6 7 8 9 