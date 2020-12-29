
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL){}
};

vector<int> printReverseListNode(ListNode* head) {

	vector<int> res;
	stack<ListNode*> stack2;
	while (head!=NULL) {
		stack2.push(head);
		head = head->next;
	}

	while (!stack2.empty()) {
		res.push_back(stack2.top()->val);
		stack2.pop();
	}
	return res;
}

int main(int argc, char* argv[]) {
	ListNode* n1 = new ListNode(2);
	ListNode* n2 = new ListNode(3);
	ListNode* n3 = new ListNode(4);
	ListNode* n4 = new ListNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = nullptr;

	vector<int> res = printReverseListNode(n1);
	for(int i=0;i<res.size();i++) {
		cout << res[i]<<endl;
	}
	return 0;
}
