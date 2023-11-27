
#include<iostream>
#include<bits/stdc++.h>

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
            // res.insert(res.begin(),temp%2+'0');
            res.insert(0,to_string(temp%2));
            carry = temp/2;
            i--;
            j--;
        }
        return carry ? "1" + res : res;
    }
};


int main() {

    string a = "11", b = "10";
    Solution s2;
    cout<<s2.addBinary(a,b)<<endl;
    return 0;
}