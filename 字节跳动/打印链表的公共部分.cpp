
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	void printCommonPart(ListNode* head1, ListNode* head2) {
		cout << "Common Part: " << endl;
		while (head1 != NULL && head2 != NULL) {
			if (head1->val > head2->val)
				head2 = head2->next;
			else if (head1->val < head2->val)
				head1 = head1->next;
			else {
				cout << head1->val << " ";
				head1 = head1->next;
				head2 = head2->next;
			}
		}
		cout << endl;
	}
};


int main(int argc, char* argv[]) {

	ListNode* head = new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);

	head->next = h2;
	h2->next = h3;
	h3->next = nullptr;

	ListNode* m = new ListNode(2);
	ListNode* m2 = new ListNode(3);
	ListNode* m3 = new ListNode(4);

	m->next = m2;
	m2->next = m3;
	m3->next = nullptr;

	Solution s;
	s.printCommonPart(head, m);

	return 0;
}
