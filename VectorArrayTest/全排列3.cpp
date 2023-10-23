
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<vector<int>> nextPermutation(vector<int>& num) {
		vector<vector<int> > res;
		sort(num.begin(), num.end());
		do {
			res.push_back(num);
		}while(next_permutation(num.begin(),num.end()));
		return res;
	}
};


int main() {

    vector<int> res {1,2,2};
    Solution s;
    vector<vector<int>> res2 = s.nextPermutation(res);
    for(auto i:res2) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}

