


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {

        unordered_map<int,int> list;
        for(auto i:deck) {
            ++list[i];
        }

        int n  = list.begin()->second;

        for(auto i: list) {
            n = __gcd(n,i.second);
            if(n==1) {
                return false;
            }
        }
        return true;
    }
};


int main() {

    vector<int> nums = {1,2,3,4,4,3,2,1};
    Solution s2;
    cout<<s2.hasGroupsSizeX(nums)<<endl;

    return 0;
}
