

// 判断是否为回文链表
#include "iostream"
#include "bits/stdc++.h"

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
    bool isPalindrome(ListNode* head) {

    	vector<int> res;

    	ListNode* pre= head;

    	while(pre!=nullptr) {
    		res.push_back(pre->val);
    		pre = pre->next;
    	}

    	for(int i=0,j=res.size()-1;i<j;i++,j--) {
    		if(res[i]!=res[j]) {
    			return false;
    		}

    	}

    	return true;
    }
};


int main(int argc, char** argv) {

	ListNode* head = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(3);
    ListNode* n5 = new ListNode(2);
    ListNode* n6 = new ListNode(1);


    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = nullptr;

    Solution s;
    cout<<s.isPalindrome(head)<<endl;
	return 0;
}