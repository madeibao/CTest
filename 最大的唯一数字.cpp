

/**
 * 
 * 首先是选择比较大的数字，然后确保数字是整个数组中的唯一出现的数字。
 * 
 */


#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {

    public:
        int largestUniqueNumber(vector<int>& A) {
            unordered_map<int,int> dict;
            int n = A.size();
            for(int i = 0; i < n;i++) {
                dict[A[i]]++;
            }

            int res = -1;
            for(auto it:dict) {
                if(1==it.second) {
                    res = max(res,it.first);
                }
            }
            return res;
        }

};

int main(int argc, char *argv[]) {

    vector<int> temp = {5,7,3,9,4,9,8,3,1};
    Solution s;
    cout<<s.largestUniqueNumber(temp)<<endl;
    return 0;
}




