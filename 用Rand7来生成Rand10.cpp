

// rand7 函数是预先定义好的内容。

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int rand10() {
     int x=INT_MAX;
        while(x>40) {
            x=7*(rand7()-1)+rand7();
        }
        return x%10+1;
    }
    int rand7() {
    	return rand()%7+1;
    }
};

int main(int argc, char *argv[]) {
	Solution s;
    for(int i=0;i<10;i++) {
        cout<<s.rand10()<<endl;
    }
	return 0;
}
