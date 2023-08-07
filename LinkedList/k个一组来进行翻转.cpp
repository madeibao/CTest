
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int val) : val(val){}
	ListNode(int val, ListNode* next) : val(val),next(nullptr) {}
};

class Solution {
public:
	ListNode* reverse2(ListNode* head,int k) {
        if(head==nullptr||k<=0) {
            return head;
        }

        int start = 0;
        ListNode* node = head;
        while(node&&++start<k) {
            node= node->next;
        }
        if(start<k) {
            return head;
        }

        ListNode* temp = node->next;
        node->next = nullptr;

        helper(head);

        head->next = reverse2(temp,k);
        return node;

	}
	ListNode* helper(ListNode* head) {
        ListNode* pre= nullptr;

        while(head!=nullptr) {
            ListNode* temp = head->next;
            head->next = pre;
            pre= head;
            head= temp;
        }

        return pre;
	}
};


int main(int argc, char** argv) {

	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);
	ListNode* h4 = new ListNode(4);
	ListNode* h5 = new ListNode(5);
	ListNode* h6 = new ListNode(6);
	ListNode* h7 = new ListNode(7);
	ListNode* h8 = new ListNode(8);



	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = h5;
	h5->next = h6;
	h6->next = h7;
	h7->next = h8;
	h8->next = nullptr;


    ListNode* res;
    Solution s;
    res = s.reverse2(head,3);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res =res->next;
    }
	return 0;
}
