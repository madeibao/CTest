


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
    	ListNode* dummy = new ListNode(-1);
    	dummy->next = head;
    	

    }
};


int main() {




	return 0;
}