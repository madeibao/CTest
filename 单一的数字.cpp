#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int sigleNumber(vector<int> &nums) {
        int result =0;
        for(int i:nums) {
            result = result ^ i;
        }
        return result;
    }
};


//
//int main(){
//    Solution ss;
//    vector<int> list3 = {2,3,3,4,4,5,5};
//    cout<<ss.sigleNumber(list3)<<endl;
//}
