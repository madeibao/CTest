
#include<iostream>
#include<bits/stdc++.h>

using namespace std; //

class Solution {
public:
    vector<int> minK(vector<int>& nums ,int k) {

        // 如果k值错误。
        if(k<0) {
            return vector<int>();
        }

        priority_queue<int> queue;

        // 首先接收k个数字。
        for(int i:nums) {
            if(queue.size()<k) {
                queue.push(i);
            }
        }

        for(int i=k;i<(int)nums.size();i++) {
            if(nums[i]<queue.top()) {
                queue.pop();
                queue.push(nums[i]);
            }
        }

        vector<int> res(k, 0);
        for(int i=0;i<k;i++) {
            res[i] = queue.top();
            queue.pop();
        }

        return res;
    }
};

int main(int argc, char* argv[]) {

    Solution s;
    vector<int> res {1,2,3,4,5};
    int k(2);

    vector<int> res2;
    res2 = s.minK(res, k);
    for(int i:res2) {
        cout<<i<<endl;
    }
    return 0;
}
