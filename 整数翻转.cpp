


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x/10 == 0) return x; //平凡情况：若x∈[-9,9]，则直接返回其本身
        int y = 0;
        while(x) {
            if(y > INT_MAX/10 || y < INT_MIN/10) //溢出
                return 0;
            y = y*10+x%10;
            x /=10;
        }
        return y;
    }
};


int main() {

	int x =321;

	Solution s;
	cout<<s.reverse(x)<<endl;
	return 0;
}