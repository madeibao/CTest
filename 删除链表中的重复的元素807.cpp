




#include<iostream>
#include<bits/stdc++.h>


using namespace std;
struct ListNode {

	int val;
	ListNode *next;
	ListNode(int v):val(v) {}
	ListNode(int v,ListNode *next):val(v),next(nullptr) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if(head==nullptr||head->next==nullptr) {
			return head;
		}

		// 如果与后面的内容相等，则不断的像后面删除。
		if(head->next!=nullptr&&head->val==head->next->val) {
			while(head->next!=nullptr&&head->val==head->next->val) {
				head = head->next;
			}

			// 从下一个节点来进行删除。
			return deleteDuplicates(head->next);
		}

		// 另一种情况。
		else {
			head->next = deleteDuplicates(head->next);
		}
		return head;
	}
};

int main(int argc, char** argv) {

	ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);


    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;

    int k =2;
    Solution s;
    ListNode *res;
    res = s.deleteDuplicates(n1);
    while(res!=nullptr) {
    	cout<<res->val<<" ";
    	res=res->next;
    }

	return 0;
}
