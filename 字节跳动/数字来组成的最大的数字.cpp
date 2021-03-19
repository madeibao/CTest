
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    /**
     * 最大数
     * @param nums int整型vector 
     * @return string字符串
     */
    
    string solve(vector<int>& nums) {
        // write code here
        auto cmp = [](int n1, int n2) -> bool {
            string a = to_string(n1), b = to_string(n2);
            return a + b > b + a;
        };
        
        sort(nums.begin(), nums.end(), cmp);
        if (nums[0] == 0) {
        	return "0";
        } 
        string ans;
        for(auto x : nums) ans += to_string(x);
        return ans;
    }
};

int main(int argc, char** argv) {

	vector<int>res = {10,2};
	Solution s;
	cout<<s.solve(res)<<endl;

	return 0;
}


