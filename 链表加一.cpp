
#include "iostream"
#include "bits/stdc++.h"

using  namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v):val(v) {}
	ListNode(int v, ListNode *next):val(v),next(nullptr) {}
};

class Solution {
public:
    ListNode* plusOne(ListNode* head) {

    	// 经过help(head),head的内容就已经改变。
        int up=help(head);
        if(up==1){
            ListNode* ans=new ListNode(1);
            ans->next=head;
            return ans;
        }
        return head;
    }

    int help(ListNode* head){
        int up=head->next==nullptr?1:help(head->next);
        head->val+=up;
        up=(head->val)/10;
        head->val%=10;
        return up;
    }
};

int main(int argc, char* argv[]) {

	ListNode* head= new ListNode(1);
	ListNode* h2 = new ListNode(2);
	ListNode* h3 = new ListNode(3);

	head->next = h2;
	h2->next = h3;
	h3->next = nullptr;

	Solution s;
	ListNode *res;
	res =s.plusOne(head);
	while( res!=nullptr) {
		cout<<res->val<<" ";
		res = res->next;
	}
	return 0;
}
