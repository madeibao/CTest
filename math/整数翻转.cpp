



#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        if(res < INT_MIN || res > INT_MAX) {
            return 0;
        }
        return (int)res;
    }
};

int main(int argc, char** argv) {

	int x = 321;
	Solution s2;
	cout<<s2.
	return 0;
}