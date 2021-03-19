

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 找缺失数字
     * @param a int整型一维数组 给定的数字串
     * @param aLen int a数组长度
     * @return int整型
     */
    int solve(int* a, int aLen) {
        // write code here
        int sum=aLen*(aLen+1)/2;
        int sum1=0;
        int i;
        for(i=0;i<aLen;i++) {
            sum1+=a[i];
        }
        return sum-sum1;
    }
};

int main(int argc, char* argv[]) {

    int res[] = {0,1,2,3,4,5,6,7,};
	Solution s;
	cout<<s.solve(res, 8)<<endl;

	return 0;
}
