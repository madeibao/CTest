
/**
 * 青蛙跳台阶问题。
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int jumpFloor(int number) {

        vector<int> res(number+1, 0);
        res[0] = 1;
        res[1] = 1;

        for(int i=2;i<=number;i++) {
            res[i] = res[i-1]+res[i-2];
        }
        return res[number];
    }
};


// 青蛙跳台阶问题。

class Solution {
public:
    int jumpFloor(int number) {
        int res = 0;
        int fOne = 1;
        int fTow = 2;
        if(number==1) return fOne;
        if(number==2) return fTow;
        for(int i=3;i<=number;i++){
            res=fOne+fTow;
            fOne=fTow;
            fTow=res;
        }
        return res;
    }
};



int main() {

    int n =4;
    Solution s;
    cout<<s.jumpFloor(n)<<endl;
    return 0;

}




