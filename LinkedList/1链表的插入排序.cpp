

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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = head;
        ListNode* curr = head->next;

        // 下一个节点不为空
        while (curr != nullptr) {
            if (curr->val < prev->val) {
                ListNode* temp = dummy;
                while (temp->next->val < curr->val) {
                    temp = temp->next;
                }
                prev->next = curr->next;
                curr->next = temp->next;
                temp->next = curr;
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;

    }
};



int main() {

	ListNode *head = new ListNode(1);
	ListNode *h2 = new ListNode(4);
	ListNode *h3 = new ListNode(3);
	ListNode *h4 = new ListNode(2);
	ListNode *h5 = new ListNode(5);
	ListNode *h6 = new ListNode(2);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = h5;
	h5->next = h6;
	h6->next = nullptr;


    Solution s;
	ListNode* res;
	res = s.insertionSortList(head);

	// Print the sorted linked list
	while (res != nullptr) {
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
	//
	return 0;
}

