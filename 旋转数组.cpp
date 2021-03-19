



#include<iostream>
#include<bits/stdc++.h>

using namespace std;
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
        m%=n;
        if(m==0){
            return a;
        }

        // 下标都是从0开始的。
        my(0,n-m-1,a);
        my(n-m,n-1,a);
        my(0,n-1,a);

        return a;
    }

    void my(int begin,int end,vector<int> &v){
        for(int i=begin,j=end;i<j;++i,--j){
            int a=v[i];
            v[i]=v[j];
            v[j]=a;
        }
    }
};

int main(int argc, char **argv)  {


	int m = 2;
	int n = 6;
	vector<int> res {1,2,3,4,5,6};
	vector<int> res2;
	Solution s;
	res2 = s.solve(n, m ,res);
	for(int i:res2) {
		cout<<i<<" ";
	}
	return 0;
}
