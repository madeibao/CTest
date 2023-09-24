

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int x):val(x),next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    	ListNode* dummy = new ListNode(0);
    	ListNode* pre = dummy;

    	ListNode* pa = l1;
    	ListNode* pb = l2;

    	while (pa&&pb) {
    		if(pa->val<=pb->val) {
    			pre->next = pa;
    			pa = pa->next;
    		}
    		else {
    			pre->next = pb;
    			pb = pb->next;
    		}
    		pre= pre->next;
    	}

    	if(pa) {
    		pre->next = pa;
    	}

    	if(pb) {
    		pre->next = pb;
    	}

    	return dummy->next;
    }
};

int main() {


    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);

    n1->next  = n2;
    n2->next  = n3;
    n3->next  = nullptr ;

    ListNode* h1 = new ListNode(2);
    ListNode* h2 = new ListNode(3);
    h1->next = h2;
    h2->next = nullptr;

    Solution s;
    ListNode* res;
    res  = s.mergeTwoLists(n1, h1);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res= res->next;
    }
    return 0;
}
