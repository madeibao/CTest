

//----------------------------------------------------------------
// 数字的按位与运算


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        while(right>left) {
            right = right&(right-1);
        }

        return right;
    }
};

int main() {

	int left(5), right(7);
	Solution s;
	cout<<s.rangeBitwiseAnd(left, right)<<endl;
	return 0;
}
