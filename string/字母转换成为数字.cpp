

#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
	public:
		int titleToNumber(strin s) {
			int i=0;
			long ans = 0;
			while (s[i]!='\0') {
				ans = ans*26+s[i]-'A'+1;
				i+=1;
			}
			return ans;
		}

};
int main(int argc, char* argv[]) {

	Solution s;
	cout<<s.titleToNumber("AB")<<endl;
	return 0;
}