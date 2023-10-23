示例 1：

输入：s = "abbxxxxzzy"
输出：[[3,6]]
解释："xxxx" 是一个起始于 3 且终止于 6 的较大分组。
示例 2：

输入：s = "abc"
输出：[]
解释："a","b" 和 "c" 均不是符合要求的较大分组。
示例 3：

输入：s = "abcdddeeeeaabbbcd"
输出：[[3,5],[6,9],[12,14]]
解释：较大分组为 "ddd", "eeee" 和 "bbb"




#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ve;
        for(int i=1; i<s.length(); ++i) {
            int index = i-1;
            while(s[i] == s[i-1]) ++i;
            if(i - index >= 3) ve.push_back({index, i-1});
        }
        return ve;
    }
};


int main(int argc, char* argv[]) {
	string s = "abcdddeeeeaabbbcd";
	vector<vector<int>> res;
	Solution s2;
	res = s2.largeGroupPositions(s);

	for(auto i:res) {
		for(auto j:i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}

