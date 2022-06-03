


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {

	
		int carry=0;

		int i= num1.size()-1;
		int j= num2.size()-1;

		string res;

		while (i>=0||j>=0) {

			int a = i>=0?num1[i--]- '0':0;
			int b = j>=0?num2[j--]- '0':0;

			int temp =a+b+carry;

			res+= temp%10+'0';
			carry = temp/ 10;
		}

		if(carry>0){
            res+="1";
		}
        reverse(res.begin(),res.end());
        return res;
    }
};



int main(int argc, char** argv) {

	string stra = "123";
	string strb = "234";

	Solution s;
	cout<<s.add(stra,strb)<<endl;
	return 0;
}