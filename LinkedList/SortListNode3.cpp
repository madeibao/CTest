
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

struct ListNode {

	int val;
	ListNode* next;
	ListNode(int val) : val(val){}
	ListNode(int val,ListNode* next): val(val),next(next) {}
};


class Solution {
public:
    ListNode* sortList(ListNode* head) {
    	priority_queue<int,vector<int>,greater<int>>  queue;

    	ListNode* cur = head;

    	while(cur!=nullptr){
            queue.push(cur->val);
    		cur = cur->next;
    	}

        ListNode* pre= head;


        while(pre!=nullptr) {

            pre->val = queue.top();
            queue.pop();
            pre =pre->next;
        }
    	return head;
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

	ListNode* res;

	Solution s2;
	res = s2.sortList(a);
	while(res!=nullptr) {
		cout<<res->val<< " ";
		res = res->next;
	}
	return 0;
}
