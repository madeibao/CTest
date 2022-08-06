
// 字符串的左旋转算法。

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	string iswell(string s, int n) {

	    // 三次逆置算法。
	    reverse(s.begin(),s.begin()+n);
	    reverse(s.begin()+n, s.end());
	    reverse(s.begin(),s.end());
        return s;
	}
};


int main(int argc, char** argv) {

    Solution s;
    string str2 = "abcdefg";
    cout<<s.iswell(str2, 2);
	return 0;
}
