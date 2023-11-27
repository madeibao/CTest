


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0,n=s.size();
        while (i < n) { // 指针没到字符串末尾进入循环
            if (i + k > n) { // 指针后面不够k个就全部反转
                reverse(s.begin()+i, s.end());
            } else {
                reverse(s.begin()+i, s.begin()+i+k);//reverse的第二个参数是指向要翻转范围的下一个
            }
            i += 2*k;
        }
        return s;
    }
};


int main() {

	string s = "abcdefg";
	int k = 2;
	Solution s2;
	cout<<s2.reverseStr(s,k)<<endl;

	return 0;
}
