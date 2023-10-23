


#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    /**
     * 比较版本号
     * @param version1 string字符串
     * @param version2 string字符串
     * @return int整型
     */
    int compare(string version1, string version2) {
        // write code here
        int v1_num = 0, v2_num = 0;
        int i1 = 0, i2 = 0;
        while(i1 < version1.size() && i2 < version2.size()) {
            v1_num = 0;
            v2_num = 0;
            
            while(i1<version1.size() && version1[i1] != '.') {
                v1_num = v1_num*10 + version1[i1++] - '0';
            }
            i1++;
            while(i2<version2.size() && version2[i2] != '.') {
                v2_num = v2_num*10 + version2[i2++] - '0';
            }
            i2++;

            if(v1_num < v2_num) {
                return -1;
            }
            else if(v1_num > v2_num){
                return 1;
            }
        }


        if(i1 < version1.size())  {
        	return 1;
        }
        else if(i2 < version2.size()){
        	return -1;
        } 
        return 0;
    }
};



int main(int argc,char **argv) {

	string str1 ="0.1";
	string str2 ="1.1";
	Solution s;
	cout<<s.compare(str1, str2)<<endl;
	return 0;

}
