
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    /**
     * max sum of the subarray
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxsumofSubarray(vector<int>& arr) {
        // write code here [1, -2, 3, 5, -2, 6, -1]
        if(arr.size()==0) return 0;
        int num=0,i=0,sum=0;
        while(i<arr.size()) {
            num=max(arr[i],arr[i]+num);
            sum=max(num,sum);
            i++;
        }
        return sum;
    }
};


int main() {

    vector<int> res {1, -2, 3, 5, -2, 6, -1};
    Solution s;
    cout<<s.maxsumofSubarray(res)<<endl;
    return 0;
}



