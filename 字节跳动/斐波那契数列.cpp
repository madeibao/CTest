
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// 方法1
// 方法2

class Solution {
public:
    int Fibonacci(int n) {

        vector<int> res(n+1,0);
        res[0] = 0;
        res[1] = 1;
        res[2] = 1;
        for(int i=3;i<=n;i++) {
            res[i]= res[i-2]+res[i-1];
        }
        return res[n];
    }
};

class Solution2 {
public:
    int Fibonacci(int n) {

       if(n==0)return 0;
       if(n==1)return 1;
       int pre =0;
       int cur =1;
       int i =2;
       int temp;
        while(i<=n) {
            temp = pre+cur;
            pre= cur;
            cur = temp;
            i++;
        }
        return cur;
    }
};


int main() {


	int n =3;
	Solution s;
	cout<<s.Fibonacci(n)<<endl;
	return 0;
}
