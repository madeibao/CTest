
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):  val(x),next(nullptr)  {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};


int main(int argc, char*argv[]) {

    ListNode* head= new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);


	head->next = h2;
	h2->next = h3;
	h3->next = head;

	Solution s;
	cout<<s.hasCycle(head);
	return 0;
}
