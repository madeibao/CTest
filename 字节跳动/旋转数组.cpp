

#include<iostream>
#include<bits/stdc++.h>
using namespace  std;


class Solution {
public:
    /**
     * 旋转数组
     * @param n int整型 数组长度
     * @param m int整型 右移距离
     * @param a int整型vector 给定数组
     * @return int整型vector
     */
    vector<int> solve(int n, int m, vector<int>& a) {
        // write code here
        if (n == 0 || (m %= n) == 0) return a;
        reverse(a.begin(), a.begin() + n - m);
        reverse(a.begin() + n - m, a.end());
        reverse(a.begin(), a.end());
        return a;
    }
};


int main() {
   Solution s;
   vector<int> res = {1,2,3,4,5,6};
   int n = 6, m =2;
   vector<int> res2;
   res2 =  s.solve(n, m, res);
   for(int i:res2) {
        cout<<i<<" ";
   }

    return 0;
}
