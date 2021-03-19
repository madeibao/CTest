



#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v):val(v),next(nullptr){}
};


class Solution {
public:
	ListNode* middle(ListNode* head) {
		ListNode* slow = head, *fast= head->next;

		while (fast&&fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		ListNode* pre = slow->next;
		slow->next = nullptr;
		return pre;
	}
};

int main(int argc, char* argv[]) {

	ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(3);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(9);
    ListNode* n6 = new ListNode(6);


    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = nullptr;


    ListNode* res;
    Solution s;
    res =s.middle(n1);
    while(res!=nullptr) {
    	cout<<res->val<<" ";
    	res = res->next;
    }
	return 0;
}
