

#include <string.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int v):val(v) {}
};

class Solution {
public:
    bool isValid(string s) {

    	unordered_map<char, char> map2 = {{')':'('},{']','['},{'}','{'}};

    	stack<char> stack2;
    	for(auto i:s) {
    		if(i=='('||i=='{'||i=='[') {
    			stack2.push(i);
    		}
    		else if(!stack2.empty()&&map2[i]==stack2.top()) {
    			stack2.pop();
    		}
    		else {
    			return false;
    		}
    	}
    	return stack2.empty();
    }
};

int main(int argc, char **argv) {


	return 0;
}