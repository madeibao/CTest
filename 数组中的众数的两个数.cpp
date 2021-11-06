

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size =nums.size();
        int a=0,b=0,cnta = 0,cntb = 0;
        vector<int> res;
        if(size==0) {
            return res;
        }

        for(int num:nums) {

            if(num==a){
                cnta ++;
            }
            else if(num==b) {
                cntb ++;
            }
            else if(cnta==0) {
                a=num;
                cnta++;
            }
            else if(cntb==0) {
                b= num;
                cntb++;
            }
            else {
                cnta--;
                cntb--;
            }
        }

        cnta = 0;
        cntb = 0;
        for(int num:nums) {
            if(num==a) {
                cnta++;
            }
            else if (num==b) {
                cntb ++;
            }
        }

        if(cnta>size/3) {
            res.push_back(a);
        }
        if(cntb>size/3) {
            res.push_back(b);
        }
        return res;
    }

};


int main() {
    Solution s;
    vector<int> temp = { 1,1,1,3,3,2,2,2};
    vector<int> temp2 = s.majorityElement(temp);
    for(unsigned int i=0;i<temp2.size();i++) {
        cout<<temp2[i]<<" ";
    }
}


