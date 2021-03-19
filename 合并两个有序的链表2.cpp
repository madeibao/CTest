


#include<iostream>
#include<bits/stdc++.h> 

using namespace std;

struct ListNode {	

	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr) {}
};

// 递归方法来实现。
// 合并两个有序的链表。
class Solution {
public:
	ListNode* combine(ListNode* headA,ListNode* headB) {

		if(headA==nullptr) {
			return headB;
		}

		if(headB==nullptr) {
			return headA;
		}

		ListNode* temp=nullptr;

		if(headA->val<headB->val) {
			temp = headA;
			temp->next = combine(headA->next, headB);
		}
		else {
			temp = headB;
			temp->next = combine(headA, headB->next);
		}
		return temp;
	}

};


int main(int argc, char* argv[]) {

	ListNode* h1 = new ListNode(1);
    ListNode* h2 = new ListNode(2);
    h1->next = h2;
    h2->next = nullptr;

    ListNode* m1 = new ListNode(3);
    ListNode* m2 = new ListNode(4);
    m1->next = m2;
    m2->next =nullptr;

    ListNode* res;
    Solution s;
    res = s.combine(h1, m1);

    while(res!=nullptr) {
        cout<<res->val<<" ";
        res = res->next;
    }

	return 0;
}
