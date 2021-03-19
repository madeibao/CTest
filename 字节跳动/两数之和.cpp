
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    /**
     *
     * @param numbers int整型vector
     * @param target int整型
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        map<int,int> mp;
        for(int i=0;i<numbers.size();i++){
            if(mp.find(target-numbers[i])!=mp.end()) {
                return {mp[target-numbers[i]],i+1};
            }
            else{
                mp[numbers[i]]=i+1;
            }
        }
        return {};
    }
};
int main() {

    vector<int> temp = {3,2,4};
    int target = 6;
    vector<int> res;
    Solution s;
    res= s.twoSum(temp , target);
    for(int i:res) {
        cout<<i<<" ";
    }
    return 0;
}
