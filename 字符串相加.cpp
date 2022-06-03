

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {

        int lena = num1.size()-1;
        int lenb = num2.size()-1;

        int temp = 0; // temporary
        string result;

        while(lena>=0||lenb>=0||temp!=0) {
            int a = lena<0?0:num1[lena--]- '0';
            int b = lenb<0?0:num2[lenb--]- '0';

            int res = a+b+temp;
            result.push_back('0'+res%10);
            temp = res/10;
        }

        if(temp!=0) {
            result.push_back('0'+temp);
        }
        reverse(result.begin(), result.end());

        return result;
    }
};

int main(int argc, char**argv) {

	string stra = "123";
	string strb = "234";
	Solution s;

	cout<<s.addStrings(stra,strb);
    return 0;
}
