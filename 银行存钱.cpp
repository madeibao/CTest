
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalMoney(int n) {

    	if(n<=7) {
    		return n*(1+n)/2;
    	}

    	// 确定有几个7
    	int temp = n/7;

    	// 确定余数
    	int temp2 = n%7;

    	// 保存结果
    	int res= 0;
    	int start = 1;


    	// 这里是完全能够整除的情况
    	// 外层循环控制数量
    	for(int i=1;i<=temp;i++) {
    		for(int j=start;j<=start+6;j++) {
    			res+=j;
    		}
    		start +=1;
    	}


    	// 确定余数情况
    	int res2=0;
    	// 如果直接的是整除的情况，那么就直接的返回
    	if(temp2==0) {
    		return res;
    	}

    	int start2 = temp+1;

        while(temp2>0) {
            res2+=start2;
            start2++;
            temp2--;
        }
    	return res+res2;
    }
};





int main(int argc, char** argv) {

	Solution s;
	int n =21;
	cout<<s.totalMoney(n)<<endl;
	return 0;
}