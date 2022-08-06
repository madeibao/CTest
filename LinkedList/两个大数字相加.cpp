
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        // write code here

        string res;
        int carry = 0;
        int N1 = s.size();
        int N2 = t.size();
        int i = N1 - 1;
        int j = N2 - 1;
        while (i >= 0 || j >= 0) {
            int val1 = i >= 0 ? s[i--] - '0' : 0;
            int val2 = j >= 0 ? t[j--] - '0' : 0;
            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            res += digit + '0';
        }

        if (carry == 1) {
            res += '1';
        }

        reverse(res.begin(), res.end());

        return res;
    }
};


int main() {

    string str2 ="123";
    string str3 ="233";
    Solution s;
    cout<<s.solve(str2,str3);
    return 0;
}
