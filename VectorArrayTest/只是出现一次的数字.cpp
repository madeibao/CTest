


#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	map<int, int> nums_record;
    	for(size_t i=0;i<nums.size();++i){
    		nums_record[nums[i]]++;
    	}
    	vector<pair<int,int>> v_nums_record(nums_record.begin(), nums_record.end());
    	std::sort(v_nums_record.begin(), v_nums_record.end(), [](pair<int,int>& l, pair<int,int>& r){
    		return l.second < r.second;
    	});
    	return v_nums_record[0].first;
    }
};

int main() {

    vector<int> res ={3,4,3,3,};
    Solution s;
    cout<<s.singleNumber(res)<<endl;
    return 0;
}



