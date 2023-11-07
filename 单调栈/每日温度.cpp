

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int Len = temperatures.size();

        stack<int> st;
        vector<int> res(Len,0);
        for(int i=0;i< Len;i++) {

        	while(!st.empty()&&temperatures[st.top()]<temperatures[i]) {
        		int t= st.top();
        		st.pop();
        		res[t] = i-t;
        	}
        	st.push(i);
        }

        return res;
    }
};


int main() {

    vector<int> nums = {73,74,75,71,69,72,76,73};
    Solution s2;
    vector<int> res;
    res = s2.dailyTemperatures(nums);
    for(auto i:res) {
        cout<<i<<" ";
    }
    return 0;
}
