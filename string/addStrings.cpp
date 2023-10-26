

#include<iostream>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int m = num1.size(), n = num2.size(), i = m - 1, j = n - 1, carry = 0;
        while (i >= 0 || j >= 0) {
            int a = i >= 0 ? num1[i--] - '0' : 0;
            int b = j >= 0 ? num2[j--] - '0' : 0;
            int sum = a + b + carry;
            res.insert(res.begin(), sum % 10 + '0');
            carry = sum / 10;
        }
        return carry ? "1" + res : res;
    }
};

int main() {

    string stra = "123", strb = "234";
    Solution s2;
    cout<<s2.addStrings(stra, strb)<<endl;
    return 0;
}



//______________________________________________________________________________________________________________________

// 二进制相加

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {

        int carry = 0;
        int i = a.size()-1;
        int j = b.size()-1;

        string res = "";
        while(i>=0||j>=0||carry!=0) {
            int ca = i>=0?a[i]-'0':0;
            int cb = j>=0?b[j]-'0':0;
            int temp = ca+cb+carry;
            res.insert(res.begin(),temp%2+'0');
            carry = temp/2;
            i--;
            j--;
        }
        return carry ? "1" + res : res;
    }
};


int main(int argc, char* argv[]) {

	string stra ="11";
	string strb = "1";

	Solution s;
	cout<<s.addBinary(stra,strb)<<endl;

	return 0;

}
