
#include<iostream>
#include<bits/stdc++.h>

using namespace std; //

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {

        // 如果不是预期的结果值。
        if(k<=0) {
            return vector<int>();
        }

        // 优先权队列来进行插入元素值。
        priority_queue<int> queue;
        for(int i:arr) {
            if(queue.size()<k) {
                queue.push(i);
            }
        }


        // 对后面的内容来进行更新之后，
        for(int i=k;i<(int)arr.size();i++) {
            if(arr[i]<queue.top()) {
                queue.pop();
                queue.push(arr[i]);
            }
        }

        vector<int> res(k,0);
        for(int i=0;i<k;i++) {
            res[i] = queue.top();
            queue.pop();
        }

        return res;
    }
};

int main(int argc, char* argv[]) {

    vector<int> nums {1,2,3,4,5,6,7,8,9};
    int k =2;
    vector<int> res;
    Solution s;
    res = s.getLeastNumbers(nums, k);
    for(int i:res) {
        cout<<i<<" ";
    }
    return 0;
}
