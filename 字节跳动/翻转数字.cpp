


#include<iostream>
#include<bits/stdc++.h>

class Solution {
public:
    int reverse(int x) {
       long long res = 0;
       while(x!=0)
       {
           res = res*10+x%10;
           x/=10;
           if(res >= INT_MAX || res <= INT_MIN)
               return 0;
       }
        return res;
    }
};



int main(int argc, char* argv[]) {

	int n = -123;
	Solution s;
	cout<<s.reverse(n)<<endl;

	return 0;
}