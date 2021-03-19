

// 从左面到右面分配一次糖果，从右面到左面分配一次糖果。
// 分苹果算法。

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * pick candy
     * @param arr int整型vector the array
     * @return int整型
     */

    
    int candy(vector<int>& arr) {
        // write code here

        if(arr.size()==0) {
        	return 0;
        }

        if(arr.size()==1) {
        	return arr[0];
        }

        vector<int> left(arr.size(), 1);
        vector<int> right(arr.size(),1);

        for(int i=1;i<arr.size();i++) {
        	if(arr[i]>arr[i-1]) {
        		left[i] = left[i-1]+1;
        	}
        }

        for(int j = arr.size()-2;j>=0;j--) {
        	if(arr[j]>arr[j+1]) {
        		right[j] = right[j+1]+1;
        	}
        }

        int res=0;
        for(int i=0;i<arr.size();i++) {
        	res+= max(left.at(i), right.at(i));
        }
        return res;
    }
};

int main(int argc, char **argv) {

	vector<int> temp = {1,1,2};
	Solution s;
	vector<int> res;
    cout<<s.candy(temp)<<endl;
	return 0;
}
