
// 最小的k 个数字。
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {

        vector<int> res2;
        if(k==0||k>input.size()) {
            return res2;
        }

        vector<int> res(k, 0);
        priority_queue<int> queue;
        for(int i=0; i<k;i++) {
            queue.push(input[i]);
        }

        for(int j=k;j<input.size();j++) {
            if(input[j]<queue.top()) {
                queue.pop();
                queue.push(input[j]);
            }
        }

        for(int i=0;i<k;i++) {
            res[i] = queue.top();
            queue.pop();
        }
        return res;
    }
};


int main(int argc, char**argv) {

    vector<int> input = {4,5,1,6,2,7,3,8};
    int k(4);

    Solution s;
    vector<int> res2 = s.GetLeastNumbers_Solution(input, k);
    for(auto i:res2) {
        cout<<i<<" ";
    }
    return 0;
}
