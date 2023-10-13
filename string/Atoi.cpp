


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {

    	if(str.empty()) {
    		return 0;
    	}
    	int signal = 1;

    	int index = 0, n = str.size(), res = 0;

    	// 处理前置的空格
    	while(index < n && str[index] == ' ') {
    		index++;
    	}


    	// 处理前置的符号表示
    	if(index < n && (str[index] == '-'|| str[index] == '+')) {
    		signal = str[index++] == '+'?1:-1;
    	}

    	// 处理数字

    	while(index < n && isdigit(str[index])) {
    		int digit = str[index]-'0';
  			if (res > (INT_MAX - digit) / 10) {
                return signal == 1 ? INT_MAX : INT_MIN;
            }
			res = res * 10 + digit;
            ++index;
    	}

    	return signal*res;
    }

};


int main(int argc, char* argv[]) {

	string s = "   -42";
	Solution s2;
	cout<<s2.myAtoi(s)<<endl;
	return 0;
}
