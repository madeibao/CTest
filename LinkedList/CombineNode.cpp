


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
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* dummy = new ListNode(-1);

		ListNode* res = dummy;

		while (list1&&list2) {

			if(list1->val<list2->val) {

				res->next = list1;
				list1 = list1->next;

			}
			else {
				res->next = list2;
				list2 = list2->next;
			}

			res = res->next;
		}

		res->next = list1==nullptr?list2:list1;
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
