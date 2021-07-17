
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int myAtoi(string str) {
        if(str.empty()) {return 0;}
        unsigned int i= 0;
        long long res = 0;
        int bol =1;
        while(i<str.size()&&str[i]==' ') ++i;
        if(i==str.size()) {
            return 0;
        }
        if(str[i]=='-'){
            bol = -1;
            ++i;
        }
        while(i<str.size()&&str[i]<='9'&&str[i]>='0') {
            res = res*10+str[i++]-'0';
            if(res>=2147483648) {
                if(bol==1) {
                    return INT_MAX;
                }
                else {
                    return INT_MIN;
                }
            }

        }

        return res*bol;

    }

};
int main() {
    string s="123";
    Solution s2;
    cout<<s2.myAtoi(s)<<endl;

    return 0;
}


