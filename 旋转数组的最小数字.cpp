
// 利用算法求旋转数组的最小值。

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int i=0, j = rotateArray.size()-1;
        while (i<j) {
        	int mid = (i+j)/2;

        	// 3 4 5 1 2 
        	if(rotateArray[mid]>rotateArray[j]) {
        		i = mid+1;
        	}

        	// 5 1 2 3 4 
        	else if(rotateArray[mid]<rotateArray[j]) {
        		j = mid;
        	}
        	else {
        		j-=1;
        	}
        }

        return rotateArray[i];
    }
};


int main(int argc, char**argv) {

	vector<int> nums= {3,4,5,1,2};
	Solution s;
	cout<<s.minNumberInRotateArray(nums)<<endl;
	return 0;
}

