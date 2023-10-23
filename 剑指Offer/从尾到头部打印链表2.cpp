
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int x):val(x),next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(nullptr) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {

    	vector<int> res;

    	while(head!=nullptr) {
    		res.push_back(head->val);
    		head = head->next;
    	}

    	reverse(res.begin(), res.end());
    	return res;
    }
};


int main() {

    ListNode *n1 =new ListNode(1);
    ListNode *n2 =new ListNode(2);
    ListNode *n3 =new ListNode(3);
    ListNode *n4 =new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = nullptr;

    Solution s2;
    vector<int> res;
    res = s2.reversePrint(n1);
    for(auto i:res){
    	cout<<i<<" "<<endl;
    }
	return 0;
}
