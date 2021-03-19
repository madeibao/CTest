
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

 struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v):val(v),next(nullptr){}
 };


class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @return ListNode类
     */


    ListNode* deleteDuplicates(ListNode* head) {
        // write code here;
        ListNode* p;
        p=head;
        while(p != NULL)  {
            while(p->next != NULL && p->val == p->next->val){
                p->next = p->next->next;
            }
            p=p->next;
        }
        return head;
    }
};


int main(int argc, char* argv[]) {


	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(1);
	ListNode* n3 = new ListNode(2);


	n1->next = n2;
	n2->next  = n3;
	n3->next  = nullptr;

	Solution s;
	ListNode * res;
	res = s.deleteDuplicates(n1);
	while(res!=nullptr) {
		cout<<res->val<<" ";
		res= res->next;
	}
	return 0;
}
