

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.length() == goal.length() && (goal + goal).find(s) != -1;
    }
};

int main() {

	string  s = "abcde", goal = "cdeab";
	Solution s2;
	cout<<s2.rotateString(s, goal)<<endl;
	return 0;
}




