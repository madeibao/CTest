
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
        if(x <= 1) {
        	return x;
        }
        
        int begin = 1;  
        int end   = x;  
        int middle = 0;  
        while(begin<=end) {  
            middle = (begin + end)/2;  
            //不要写成middle*middle==x，会溢出  
            if(middle==x/middle) {  
                return middle;  
            } 
            else {  
                if (middle<x/middle) {  
                    begin = middle + 1;  
                } 
                else {  
                    end = middle - 1;  
                }  
            }  
              
        }   
        //结束条件end一定<begin，所以返回end  
        return end;  
    }
};


int main(int argc, char* argv[]) {

	int n = 15;
	Solution s; 
	cout<<s.sqrt(n)<<endl;

	return 0;
}