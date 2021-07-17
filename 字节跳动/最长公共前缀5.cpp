

#include<iostream>
#include<bits/stdc++.h>
using namespace std; //


class Solution {
public:
    /**
     *
     * @param strs string字符串vector
     * @return string字符串
     */
		string longestCommonPrefix(vector<string>& strs) {

			if(!strs.size()) {
				return "";
			}

			string temp = strs[0];
			for(int i=1;i<strs.size();i++) {
				temp = helper(temp, strs[i]);
				if(!temp.size()) {
					break;
				}
			}

			return temp;
    	}

    	string helper(string stra, string strb) {
    		int lena = stra.size();
    		int lenb = strb.size();
    		int len = min(lena, lenb);
    		int i = 0;

    		while(i< len) {

    			if(stra[i]==strb[i]) {
    				i++;
    			}
    			else {
    				break;
    			}
    		}
    		return stra.substr(0, i);

    	}
};

int main(int argc, char **argv) {

	vector<string> res  {"abca","abc","abca","abc","abcc"};

	Solution s;
	cout<<s.longestCommonPrefix(res);
	return 0;
}
