


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
	ListNode* add(ListNode* heada, ListNode* headb) {

		ListNode* dummy = new ListNode(-1);
		ListNode* temp = dummy;

		ListNode* p = heada;
		ListNode* q = headb;

		int val = 0;
		while (p || q || val) {

			if(p) {
				val+= p->val;
				p  = p->next;
			}

			if(q) {
				val+= q->val;
				q = q->next;
			}

			ListNode* node = new ListNode(val%10);
			temp->next = node;
			temp= temp->next;
			val = val/10;
		}

		return dummy->next; //
	}

};


int main(int argc, char** argv) {

	ListNode* a = new ListNode(2);
    ListNode* a2 = new ListNode(4);
    ListNode* a3 = new ListNode(3);

    a->next = a2;
    a2->next = a3;
    a3->next = nullptr;


    ListNode* b = new ListNode(5);
    ListNode* b2 =new ListNode(6);
    ListNode* b3 =new ListNode(4);
    b->next = b2;
    b2->next = b3;
    b3->next = nullptr;

    Solution s;
    ListNode* res;
    res= s.add(a, b);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res=res->next;
    }

   	return 0;
}
