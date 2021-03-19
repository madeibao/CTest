



// 数组的峰值的所在的位置。
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    /**
     * 寻找最后的山峰
     * @param a int整型一维数组
     * @param aLen int a数组长度
     * @return int整型
     */
    int solve(int* a, int aLen) {
        // write code here

        if(a==nullptr||aLen==0) {
            return 0;
        }

        // 只要找到了变化的位置，就会导致峰值的产生。
        for(int i = aLen-1;i>=0;i--) {
            if(a[i]>=a[i-1]) {
                return i;
            }
        }
        return 0;
    }
};


int main() {

	int res[] = {2,4,1,2,7,8,4};
	Solution s;
	cout<<s.solve(res, sizeof(res)/sizeof(res[0]));
	return 0;
}
