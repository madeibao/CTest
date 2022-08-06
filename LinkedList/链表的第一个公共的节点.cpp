
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
}


int main(int argc, char* argv[]) {

	ListNode* a1 = new ListNode(4);
	ListNode* a2 = new ListNode(1);

	ListNode* b1 = new ListNode(5);
	ListNode* b2 = new ListNode(0);
	ListNode* b3 = new ListNode(1);

	ListNode* c1 = new ListNode(8);
	ListNode* c2 = new ListNode(4);
	ListNode* c3 = new ListNode(5);

	a1->next = a2;

	b1->next = b2;
	b2->next = b3;

	c1->next = c2;
	c2->next = c3
	c3->next = nullptr;

	a2->next = c1;
	b2->next = c1;

	Solution s;
	ListNode* res = s.getIntersectionNode(a1,b1);
	while (res!=nullptr) {
		cout<<res.val<<endl;
		res = res->next;
	}

}