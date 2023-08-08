

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {

        for(int i=0,j=s.size()-1;i<j;i++,j--) {
            const char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
};

int main(int argc, char** argv) {

	vector<char> s {'h','e','l','l','o',};
	Solution s2;
	s2.reverseString(s);
	for(auto i:s) {
		cout << i <<" "<<endl;
	}
	return 0;
}