
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

    	// 按照第一维度的数据来进行排序。
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>&b) {
            return a[0] < b[0];
        });


        // 这里定义的是小根堆。
        priority_queue<int, vector<int>, greater<int>> heap;

        for (int i = 0; i < intervals.size(); i++) {
            if (!heap.empty() && heap.top() <= intervals[i][0]) {
                heap.pop();
            }
            heap.push(intervals[i][1]);
        }
        return heap.size();
    }
};


int main() {
    vector<vector<int>> res {{0, 30},{5,10},{15, 20},};
    vector<vector<int>> res2 {{7,10},{2,4}};
    Solution s;

    cout<<s.minMeetingRooms(res)<<endl;
    cout<<s.minMeetingRooms(res2)<<endl;
    return 0;
}




