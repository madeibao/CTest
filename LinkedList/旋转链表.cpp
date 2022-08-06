

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v):val(v),next(nullptr){}
    ListNode(int v, ListNode* next):val(v),next(nullptr){}
};

class Solution {
public:
	ListNode* rotate(ListNode*head, int k) {
		if(k<=0) {
			return head;
		}

		// ListNode* p = head;
		int n=0;
		for(auto p=head;p!=nullptr;p=p->next) {
			n+=1;
		}

		k%=n;
		ListNode* first = head, *second = head;

		while(k--) {
			first = first->next;
		}

		while(first->next!=nullptr) {
			first = first->next;
			second = second->next;
		}

		first->next=head;
		head = second->next;
		second->next= nullptr;

		return head;
	}
};

int main(int argc, char*argv[]) {
    ListNode *head = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;

    int k = 2;
    Solution s;
    ListNode* res;
    res = s.rotate(head, k);
    while(res!=nullptr) {
        cout <<res->val<<" ";
        res= res->next;
    }
    return 0;
}
