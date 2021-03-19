
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v)	:val(v),next(nullptr){}
};

class Solution {
public:
	ListNode* reverse(ListNode* head ) {
		ListNode* pre = nullptr;
		while( head !=nullptr ) {
			ListNode* temp = head->next;
			head->next = pre;
			pre= head;
			head= temp;
		}

		return pre;
	}
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here


        head1 = reverse(head1);
        head2 = reverse(head2);

        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        dummy->next = nullptr;

        ListNode* point=  dummy;

        while(head1||head2) {
        	int val1 = head1==nullptr?0:head1->val;
        	int val2 = head2==nullptr?0:head2->val;

        	int temp = val1 + val2 + carry;
        	point->next  = new ListNode(temp%10);
        	point = point->next;

        	carry = temp/10;

        	head1 = head1==nullptr?nullptr:head1->next;
        	head2 = head2==nullptr?nullptr:head2->next;

        }

        if(carry>0) {
        	point->next = new ListNode(carry);

        }

        return reverse(dummy->next);
    }
};


int main(int argc, char** argv) {

	ListNode* head= new ListNode(1);
	ListNode* h2 = new ListNode(2);

	head->next = h2;
	h2->next = nullptr;

	ListNode* r2 = new ListNode(1);
	ListNode* r3 = new ListNode(8);

	r2->next = r3;
	r3->next = nullptr;

	ListNode* res;
	Solution s;
	res=  s.addInList(head, r2);
	while(res!=nullptr) {
		cout<<res->val<<" ";
		res = res->next;
	}


	return 0;
}


