

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int n = str.size(), j = n;
        for (int i = n - 1; i > 0; --i) {
            if (str[i] >= str[i - 1]) continue;
            --str[i - 1];
            j = i;
        } 

        for (int i = j; i < n; ++i) {
            str[i] = '9';
        }

        return stoi(str);
    }
};

int main(int argc, char* argv[]) {

	int N = 1234;
	Solution s2;
	cout<<s2.monotoneIncreasingDigits(N)<<endl;
	return 0;
}