

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
const int MAXSIZE = 1001;
int maxLen[MAXSIZE][MAXSIZE];

int maxLength(string str1, string str2) {

	for(int i=0;i<=str1.size();i++) {
		maxLen[i][0] = 0;
	}

	for(int j=0;j<=str2.size();j++) {
		maxLen[0][j] = 0;
	}

	for(int i=1;i<=str1.size();i++) {
		for(int j=1;j<=str2.size();j++) {
			if(str1[i]==str2[j]) {
				maxLen[i][j] = maxLen[i-1][j-1]+1;
			}
			else {
				maxLen[i][j] = max(maxLen[i-1][j],maxLen[i][j-1]);
			}
		}
	}
	return maxLen[str1.size()][str2.size()];
}

int main(int argc, char** argv) {
    string s1;
    while(cin>>s1){
        string s2=s1;
        reverse(s2.begin(),s2.end());
        cout<<s1.size()-maxLength(s1,s2)<<endl;
    }
    return 0;
}