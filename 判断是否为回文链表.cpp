

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(nullptr){}
};

class Solomon {

public:
	bool isReverse(ListNode* head) {
		vector<int> store;

		ListNode* cur = head;
		while (cur!=nullptr) {
			store.push_back(cur->val);
			cur = cur->next;
		}
		int i=0,j = store.size()-1;
		while (i<j) {
			if(store[i]!=store[j]) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
};


int main(int argc, char* argv[]) {

	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(1);
	ListNode* n4 = new ListNode(2);

	n2->next = n3;
	n3->next = n4;
	n4->next = nullptr;

	Solomon s;
	cout<<s.isReverse(n2)<<endl;
	return 0;
}
