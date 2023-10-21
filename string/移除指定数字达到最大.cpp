

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans = "0";
        for(int i = 0; i < number.size(); ++i)
        {
            if(number[i] == digit)
            {
                string sub = number.substr(0, i) + number.substr(i+1);
                if(sub > ans)
                    ans = sub;
            }
        }
        return ans;
    }
};

int main() {

    string str ="1231";
    char c = '1';
    Solution s2;
    cout<<s2.removeDigit(str,c)<<endl;
    return 0;
}
