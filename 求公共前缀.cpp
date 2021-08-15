
#include<iostream>
#include<bits/stdc++.h>

using namespace std; 
class Solution {
	public:
		string common(vector<string> & strs) {
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

		string helper(const string& stra, const string& strb) {

			int lena = stra.size();
			int lenb = strb.size();
			int len =min(lena, lenb);
			int index  = 0;

			while (index < len) {
				if(stra[index] ==strb[index]) {
					index++;
				}
				else {
					break;
				}
			}
			return stra.substr(0,index);
		}
};


int main(int argc, char* argv[]) {

	Solution s;
	vector<string> strs {"fly", "flower", "flame"};
	cout<<s.common(strs)<<endl;

	return 0;
}