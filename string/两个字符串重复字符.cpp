


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool hasSameChar(const string stra, const string strb) {

            for(int i=0;i<stra.size();i++) {
                if(strb.find(stra[i])!=string::npos) {
                    return true;
                }
            }
            return false;
        }
};

int main() {

    Solution s2;
    cout<<s2.hasSameChar("abc","edf")<<endl;
    return 0;
}
