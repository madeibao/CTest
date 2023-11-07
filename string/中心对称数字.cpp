

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool isStrobogrammatic(string num)
	{
	    if (num.empty()) {
	        return false;
	    }
	    size_t len = num.size();
	    unordered_map<char, char> table{{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
	    for (size_t i = 0; i < len / 2; ++i) {
	        if (table[num[i]] != num[len - 1 - i]) {
	            return false;
	        }
	    }
	    return true;
	}
};


int main() {

    Solution s2;
    cout<<s2.isStrobogrammatic("8968");

    return 0;
}
