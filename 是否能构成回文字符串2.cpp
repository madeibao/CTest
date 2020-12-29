
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {

    public:
    bool canPermute(string s) {
        if(s.size()<2) {
            return 1;
        }

        unordered_map<char, int> temp;
        for(unsigned int i=0; i<s.size();i++) {
            temp[s[i]]++;
        }

        int cnt=0;
        for(auto &i:temp) {
            if(i.second&1) {
                cnt++;
            }
        }
        return cnt<2;
    }
};

int main(int argc,char *argv[]) {
    string ss="moom";
    Solution s;
    cout<<s.canPermute(ss)<<endl;
}




