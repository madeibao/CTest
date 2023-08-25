

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while(l < r)
        {
            int mid = (l + r + 1ll) / 2;
            if(mid <= x / mid) l = mid;
            else
            {
                r = mid - 1;
            }
        }
        return l;
    }
};


class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        long long mid = 0;

        while(left <= right) {
            mid =   left + (right-left)/2;
            if (mid *mid == x) {
                return mid;
            } else if (mid* mid < x) {
                left = mid + 1;
            } else if(mid* mid > x) {
                right = mid - 1;
            }
        }
        
        return right;
    }
};



int main(int argc, char** argv) {

	Solution s2;
	cout<<s2.mySqrt(16)<<endl;
	return 0;
}