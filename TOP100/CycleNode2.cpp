


//============================================================================
// 环形链表的入口地址


#include <string.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int v):val(v) {}
	ListNode(int v,ListNode* next): val(v), next(nullptr) {}
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // 首先是快慢指针
        while(true) {
            if(fast==nullptr||fast->next==nullptr) {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) {
                break;
            }
        }

        fast = head;
        while(fast!=slow) {
            fast= fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main(int argc, char** argv) {


	ListNode* head = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);


    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n3;

    ListNode* res;
    Solution s;
    res = s.detectCycle(head);
    while( res!=nullptr) {
    	cout<<res->val<<" ";
    	if(res->val==6) {
            break;
    	}
    	res = res->next;
    }
	return 0;
}
