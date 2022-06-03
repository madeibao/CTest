


#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    string addStrings(string num1, string num2) {
        const int M = num1.size();
        const int N = num2.size();
        string res;
        int p1 = M - 1;
        int p2 = N - 1;
        int carry = 0;
        while (p1 >= 0 || p2 >= 0 || carry > 0) {
            int cur1 = p1 >= 0 ? num1[p1] - '0' : 0;
            int cur2 = p2 >= 0 ? num2[p2] - '0' : 0;
            int sum = cur1 + cur2 + carry;
            carry = sum >= 10 ? 1 : 0;
            sum = sum >= 10 ? sum - 10 : sum;
            res += to_string(sum);
            p1 --;
            p2 --;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


int main(int argc, char* argv[]) {

	string stra ="123";
	string strb ="234";
	Solution s;
	cout<<s.addStrings(stra,strb);
	return 0;

}