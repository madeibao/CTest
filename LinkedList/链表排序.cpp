

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v):val(v),next(nullptr){}
    ListNode(int v, ListNode* next):val(v),next(nullptr){}
};

class Solution {
public:
	ListNode* sortListNode(ListNode* head) {

		if(head==nullptr||head->next==nullptr) {
    		return head;
    	}

    	ListNode* nodea = head;
    	ListNode* midNode = mid(head);

    	nodea = sortListNode(nodea);
    	midNode = sortListNode(midNode);

    	return merge(nodea, midNode);
	}

    //双指针找单链表中点模板
    ListNode* mid(ListNode* head)
    {
        ListNode *slow = head, *fast = head->next;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;

        }

        ListNode* mid = slow->next;
        slow->next = nullptr;           //断尾

        return mid;
    }


    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        ListNode *dummy = new ListNode(0), *p = dummy;

        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->val < head2->val)
            {
                p = p->next = head1;
                head1 = head1->next;
            }
            else
            {
                p = p->next = head2;
                head2 = head2->next;
            }
        }

        if (head1 != nullptr) p->next = head1;
        if (head2 != nullptr) p->next = head2;

        return dummy->next;
    }
};


int main(int argc, char** argv) {

	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(4);
	ListNode* c = new ListNode(3);
	ListNode* d = new ListNode(2);
	ListNode* e = new ListNode(5);
	ListNode* f = new ListNode(2);


	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = nullptr;

	Solution s;
	ListNode* res;
	res = s.sortListNode(a);
	while(res!=nullptr) {
		cout <<res->val<<" ";
		res = res->next;
	}

	return 0;
}

