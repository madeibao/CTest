

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 反转字符串
     * @param str string字符串
     * @return string字符串
     */
    string solve(string str) {
        // write code here
        reverse(str.begin(),str.end());
        return str;
    }
};


int main() {

	string str ="abc";
	Solution s;
	cout<<s.solve(str)<<endl;

	return 0;
}
