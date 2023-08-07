
#include<iostream>
using namespace std;

class Solution{
public:
    int newInteger(int n) {
        long res=0,base =1;
        while(n>0) {
            res += n%9*base;
            base *= 10;
            n /=10;
        }
        return res;
    }

};

int main() {
    Solution s;
    cout<<s.newInteger(15)<<endl;
}


