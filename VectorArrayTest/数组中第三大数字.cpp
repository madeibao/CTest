


// set是一种包含已排序对象的关联容器。set/multiset会根据待定的排序准则，


#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
using namespace std;


class Solution {
public:
    int thirdMax(vector<int> &nums) {
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
            if (s.size() > 3) {
                s.erase(s.begin());
            }
        }
        if (s.size() == 3)
            return *s.begin();
        return *s.rbegin();
    }
};

int main() {

	vector<int> nums = {2,2,3,1};
	Solution s2;
	cout<<s2.thirdMax(nums)<<endl;
	return 0;
}


set<int> set2
for(int i=0;i<nums.size();i++) {
    set2.insert(nums[i]);
    if(set2.size()>3) {
        set2.erase(set2.begin());
    }
}

return *set2.begin();