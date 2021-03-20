
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr) {}
};


class Solution {
public:
	ListNode* deleteNode(ListNode* head,int n) {
		if(n<=0) {
			return head;
		}

		ListNode* slow = head;
		ListNode* fast = head;
		while(n-->0) {
			fast = fast->next;
		}

		
		while(fast->next!=nullptr) {
			slow = slow->next;
			fast = fast->next;
		}

		slow->next = slow->next->next;
		return head;
	}
};


int main(int argc, char* argv[]) {

    ListNode* head = new ListNode(1);
    ListNode* h2 = new ListNode(2);
    ListNode* h3 = new ListNode(3);
    ListNode* h4 = new ListNode(4);

    head->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = nullptr;

    int k =2;
    ListNode* res;
    Solution s;
    res = s.deleteNode(head, k);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res= res->next;
    }
    return 0;
}




