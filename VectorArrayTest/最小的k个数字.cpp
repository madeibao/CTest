
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int>vec(k, 0);
        if (k == 0) { // 排除 0 的情况
            return vec;
        }
        priority_queue<int> Q;
        for (int i = 0; i < k; ++i) {
            Q.push(arr[i]);
        }
        for (int i = k; i < (int)arr.size(); ++i) {
            if (Q.top() > arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            vec[i] = Q.top();
            Q.pop();
        }
        return vec;
    }
};

int main(int argc, char* argv[]) { //

    vector<int> res = {1,2,3,4,5};
    int k =2;
    vector<int> temp;
    Solution s;
    temp = s.getLeastNumbers(res,k);
    for(unsigned int i=0;i<temp.size();i++) {
        cout<<temp.at(i)<<" ";
    }
    return 0;
}



