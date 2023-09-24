

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int val) : val(val){}
	ListNode(int v, ListNode* next): val(v), next(nullptr)	 {}
};


class Solution {
public:
	bool hasCycle(ListNode *head) {
        
		if(head==nullptr||head->next==nullptr) {
			return false;
		}
		ListNode *fast= head;
		ListNode *slow= head;

		while(head!=nullptr&&head->next!=nullptr) {
			fast =fast->next->next;
			slow = slow->next;
			if(fast==slow) {
				return true;
			}
		}
		return false;

    }
};

int main(int argc, char **argv) {	

	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);
	ListNode* h4 = new ListNode(3);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = head;

	Solution s;
	cout<<s.hasCycle(head)<<endl;
	return 0;
}