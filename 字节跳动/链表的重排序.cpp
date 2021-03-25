

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int val) : val(val), next(nullptr)	{}
};

class Solution {
public:
    ListNode* sortInList(ListNode* head) {
        // write code here

        if(!head||!head->next) {
        	return head;
        }

        // 第二部分的开始节点值。
        ListNode* middle = middle2(head);
        return merge(sortInList(head), sortInList(middle));
    }

    // 找到中间的节点。
	ListNode* middle2(ListNode* head) {
        ListNode*slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* res = slow->next;
        slow->next = nullptr;
        return res;
	}

	ListNode* merge(ListNode*heada, ListNode* headb) {
		if(!heada) {
			return headb;
		}

		if(!headb) {
			return heada;
		}

		ListNode* res;
		if(heada->val<=headb->val) {
			res = heada;
			res->next = merge(heada->next, headb);
		}
		else {
			res= headb;
			res->next = merge(heada, headb->next);
		}
		return res;
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
    res =s.sortInList(n1);
    while( res!=nullptr) {
    	cout<<res->val<<" ";
    	res = res->next;
    }
	return 0;
}

