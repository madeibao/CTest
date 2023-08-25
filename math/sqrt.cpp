


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int i=0;
        if(x==0){
            return 0;
        }
        if(x==1){
            return 1;
        }
        for(i=1;i<x/2;i++){
            if(x/i>=i&&x/(i+1)<(i+1))break;
        }
        return i;
    }
};

int main(int argc, char** argv) {

	Solution s2;
	cout<<s2.mySqrt(16)<<endl;
	return 0;
}