#include<iostream>
#include<bits/stdc++.h>

using namespace std; 

class Solution {
public:
    int strToInt(string str) {
        int res = 0;
        int i = 0;
        int flag = 1;
        // 1. 检查空格
        while (str[i] == ' ') { i++; }
        // 2. 检查符号
        if (str[i] == '-') { flag = -1; }
        if (str[i] == '+' || str[i] == '-') { i++; }
        // 3. 计算数字
        while (i < str.size() && isdigit(str[i])) {
            int r = str[i] - '0';
            // ------ 4. 处理溢出，这是关键步骤 ------
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7)) { 
                return flag > 0 ? INT_MAX : INT_MIN;
            }

            // ------------------------------------
            res = res * 10 + r;
            i++;
        }
        return flag > 0 ? res : -res;
    }
};

int main(int argc, char* argv[]) {

	string str="1223";
	Solution s;
	cout<<s.strToInt(str)<<endl;
	return 0;
}