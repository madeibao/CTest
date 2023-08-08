#include<iostream>
#include<deque>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    //方法2
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int,vector<int>,greater<int>> q;  //小顶堆
        for(int i=0;i<nums.size();i++)
        {
            if(i<k)
            {
                q.push(nums[i]);
            }
            else {
                if(nums[i]>q.top())  //不断更新顶部的值
                {
                    q.pop();
                    q.push(nums[i]);
                }
            }
        }
        return q.top();
    }
};


int main()
{
    vector<int> nums {2,3,1,9,3,10,2,12};
    int k(3);
    int res;
    Solution s2;
    res = s2.findKthLargest(nums, k);
    cout<<res<<" "<<endl;
	return 0;
}
