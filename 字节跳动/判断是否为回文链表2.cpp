
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v)	:val(v),next(nullptr){}
};

class Solution {
public:
    /**
     *
     * @param head ListNode类 the head
     * @return bool布尔型
     */

    bool isPail(ListNode* head) {
        // write code here

        vector<int> res;
        ListNode* pre = head;
        while(pre!=nullptr) {
        	res.push_back(pre->val);
        	pre= pre->next;
        }

        int i =0,j = res.size()-1;
        while(i<=j) {
        	if(res[i++]!=res[j--]) {
        		return false;
        	}
        }
        return true;
    }
};

int main() {


	ListNode* head = new ListNode(1);
	ListNode* h2 =  new ListNode(2);
	ListNode* h3 = new ListNode(1);

	head->next = h2;
	h2->next = h3;
	h3->next = nullptr;

	Solution s;
	ListNode * res;
    cout<<s.isPail(head)<<endl;
	return 0;
}
