
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v)	:val(v),next(nullptr){}
};

class Solution {
public:
    /**
     *
     * @param l1 ListNode类
     * @param l2 ListNode类
     * @return ListNode类
     */

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // write code here

        ListNode* res=nullptr;

        // 递归一定有结束的条件
        if(l1==nullptr) {
        	return l2;
        }

        if(l2==nullptr) {
        	return l1;

        }
        if(l1->val<=l2->val) {
        	res=l1;
        	res->next = mergeTwoLists(l1->next, l2);
        }
        else {
        	res= l2;
        	res->next = mergeTwoLists(l1, l2->next);
        }

        return res;
    }
};



int main(int argc, char** argv) {

	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	head->next = h2;
	h2->next = nullptr;


	ListNode* m1 = new ListNode(2);
	ListNode* m2 =new ListNode(3);

	m1->next = m2;
	m2->next = nullptr;

	Solution s;
	ListNode * res;
	res = s.mergeTwoLists(head, m1);
	while(res!=nullptr) {
		cout<<res->val<<" ";
		res = res->next;
	}

	return 0;
}
