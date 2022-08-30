


// 数组中的消失的数字


#include "iostream"
#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> has ;
        vector<int> res ;
        has.resize( nums.size() ) ; //开一个nums.size()肯定是够用的
        for ( int i = 0 ; i < nums.size() ; i ++ ) {
            has[nums[i] -1] ++ ; //将原数组的1放在has[0]的位置，以此类推
        }


        for ( int i = 0 ; i < nums.size() ; i ++ ) {

        	// 对应的数组的位置上是空的位置，那么把数字来推进去
            if ( has[i] == 0 ) {
                res.push_back( i + 1 ) ;
            }
        }
        return res ;
    }
};



int main(int argc, char* argv[]) {


	vector<int> nums = {4,3,2,7,8,2,3,1};
	vector<int> res;
	Solution s;
	res = s.findDisappearedNumbers(nums);
	for(int i=0;i<res.size();i++) {
		cout<<res.at(i)<<endl;
	}
	return 0;
}
