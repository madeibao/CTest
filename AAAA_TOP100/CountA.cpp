

// 2169. 得到 0 的操作数


#include "iostream"
#include "bits/stdc++.h"

using namespace std;


class Solution {
public:
    int countOperations(int num1, int num2) {
        	
    	if(num1==num2) {
    		return 1;
    	}

    	int ans = 0;
    	while(abs(num1-num2)!=0) {
    		if(num1<num2) {
    			num2 = num2-num1;
    			ans++;
    		}
    		else {
    			num1 = num1-num2;
    			ans++;
    		}
    	}
    	return ans;
    }
};

int main(int argc, char** argv) {

	int num1 = 10, num2 = 10;
	Solution s;
	cout<<s.countOperations(num1, num2)<<endl;
	return 0;
}