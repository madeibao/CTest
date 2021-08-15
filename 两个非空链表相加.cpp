
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int v):val(v){}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> x;
        stack<int> y;
        while (l1) { x.push(l1->val); l1 = l1->next; }
        while (l2) { y.push(l2->val); l2 = l2->next; }
        ListNode* node = nullptr;
        int over = 0;
        while (!x.empty() || !y.empty() || over > 0) {
            int sum_ = over;
            if (!x.empty()) { sum_ += x.top(); x.pop(); }
            if (!y.empty()) { sum_ += y.top(); y.pop(); }

            // 从后面向前面来进行添加。
            ListNode* temp = new ListNode(sum_ % 10);
            temp->next = node;
            node = temp;
            over = sum_ / 10;
        }
        return node;
    }
};


int main(int argc, char **argv) {
	ListNode* head = new ListNode(7);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(4);
	ListNode* h4 = new ListNode(3);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = nullptr;

	ListNode* ma = new ListNode(5);
	ListNode* mb = new ListNode(6);
	ListNode* mc = new ListNode(4);

	ma->next = mb;
	mb->next = mc;
	mc->next = nullptr;

	Solution s;
	ListNode* res;

	res =s.addTwoNumbers(head, ma);
	while(res!=nullptr) {
		cout<<res->val<<" ";
		res =res->next;
	}


	return 0;
}
