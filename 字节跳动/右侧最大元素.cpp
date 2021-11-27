

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int len = arr.size();
        for(int i = 0; i < len; i++){
            int max = -1;
            // 右侧的内容不断的循环
            for(int j = i + 1;j< len; j++){
                if(arr[j] > max)
                 max = arr[j];
            }
            arr[i] = max;
        }
        return arr;
    }
};




int main() {

    vector<int> nums {17,18,5,4,6,1};
    Solution s;
    vector<int> res;
    res = s.replaceElements(nums);
    for(auto i:res){
        cout<<i<<endl;
    }
    cout<<0<<endl;
    return 0;
}




