


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

    	if(strs.size()==0) {
    		return nullptr;
    	}

    	string res= strs[0];
    	for(int i=1;i<strs.size();i++) {
    		res = helper(res, strs[i]);
    	}

    	return res;
    }

    string helper(const string stra, const string strb) {

    	int lena = stra.size();
    	int lenb = strb.size();

    	int j = 0;

    	int len = max(lena, lenb);
    	while (j < len) {
    		if(stra[j]!=strb[j]) {
    			break;
    		}
    		else {
    			j++;
    		}
    	}

    	return stra.substr(0,j);
    }
};


int main(int argc, char* argv[]) {


	vector<string> strs {"flower","flow","flight"};
	string res;
	Solution s;
	res = s.longestCommonPrefix(strs);
	cout<<res<<endl;
	return 0;
}
