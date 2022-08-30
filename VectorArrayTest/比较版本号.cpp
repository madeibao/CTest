
#include "iostream"
#include "bits/stdc++.h" 

using namespace std;

class Solution {
public:
	int compareVersion(string s1, string s2) {
        for(int i = 0, j = 0; i <s1.size() || j < s2.size(); ) {
            int v1 = 0;
            while(i < s1.size()&&s1[i]!='.') {
            	v1 = v1*10 + s1[i++]-'0'; 
        	}
            i++;
            int v2 = 0;
            while(j < s2.size()&&s2[j]!='.') {
            	v2 = v2*10 + s2[j++]-'0';
            }
            j++;
            if(v1>v2) {
            	return 1;
            }
            else {
            	if(v1<v2){
            		return -1;
            	} 
            }
        }
        return 0;
    }
};


int main(int argc, char** argv) {

	string version1 = "1.01", version2 = "1.001";
	Solution s;
	cout<<s.compareVersion(version1,version2);
	return 0;
}



