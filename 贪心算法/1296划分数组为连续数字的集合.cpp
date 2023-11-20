



#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {

        int n = nums.size();
        if(n%k!=0) {
            return false;
        }

        sort(nums.begin(),nums.end());
        unordered_map<int, int> map2;
        for(auto &i:nums) {
            map2[i]++;
        }

        for(auto &i:nums) {
            if(!map2[i]) {
                continue;
            }
            for(int j=0;j<k;j++) {
                int num = i+j;
                if(!map2[num]) {
                    return false;
                }
                map2[num]--;
                if(map2[num]==0) {
                    map2.erase(num);
                }
            }
        }

        return true;
    }
};


int main() {


    return 0;
}