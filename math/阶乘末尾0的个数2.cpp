#include <iostream>
#include <bits/stdc++.h>

// 求阶乘的末尾的0的个数。

using namespace std;

class Solution {
public:
    int gettraining(int num) { 
        int res= 0;
        while(num>0) {
            res+=num/5;
            num = num/5;
        }
        return res;
    }
};
int main(int argc, char* argv[])  {
    Solution s; 
    cout<<s.gettraining(10)<<endl;
    return 0;
}


