

// leetcode 252的解法。
// 会议室

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {

public:
	bool canAttendMeetings(vector<vector<int>>& intervals) {
		if(intervals.size()==0) {
			return true;
		}
		
		// 首先按照的是嵌套列表的第一个数字大小来进行排序。
		sort(intervals.begin(), intervals.end());
		for(int i=0;i<intervals.size()-1;i++) {

			if(intervals[i][1]>intervals[i+1][0]) {
				return false;
			}
		}
		return true;

	}
};


int main() {
    vector<vector<int>> res {{0, 30},{5,10},{15, 20},};
    vector<vector<int>> res2 {{7,10},{2,4}};
    Solution s;
    cout<<s.canAttendMeetings(res)<<endl;
    cout<<s.canAttendMeetings(res2)<<endl;
    return 0;
}
