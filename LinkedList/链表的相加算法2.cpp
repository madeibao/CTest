

#include "iostream"
#include "bits/stdc++.h"

using namespace std; //
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v):val(v),next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> a,b;

        while(l1!=nullptr) {
            a.push(l1->val);
            l1 = l1->next;
        }

        while(l2!=nullptr) {
            b.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;

        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy;

        while(!a.empty()||!b.empty()||carry!=0) {

            int m = !a.empty()?a.top():0;
            int n = !b.empty()?b.top():0;

            int sum = m+n+carry;
            pre->next = new ListNode(sum%10);
            pre = pre->next;
            carry = sum/10;
            if(!a.empty()) {
                a.pop();
            }
            if(!b.empty()) {
                b.pop();
            }
        }
        return reverseList(dummy->next);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* first = NULL;
        while(head!=NULL){

            ListNode* result = new ListNode(head->val);
            result->next = first;
            first = result;
            head = head->next;

        }
        return first;
    }
};

int main() {

	ListNode *head = new ListNode(7);
	ListNode *h2 = new ListNode(2);
	ListNode *h3 = new ListNode(4);
    ListNode *h4 = new ListNode(3);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
    h4->next = nullptr;

    ListNode *ma = new ListNode(5);
	ListNode *mb = new ListNode(6);
	ListNode *mc = new ListNode(4);

	ma->next = mb;
	mb->next = mc;
	mc->next = nullptr;

	Solution s;
	ListNode * res;

	res = s.addTwoNumbers(head, ma);
	while(res!=nullptr) {
		cout<<res->val<<" ";
		res =res->next;
	}
	return 0;
}
