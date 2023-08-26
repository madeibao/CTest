



#include "iostream"
#include "bits/stdc++.h"

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int val) : val(val){}
	ListNode(int val, ListNode* next) : val(val),next(nullptr) {}
};

class Solution {
    public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if(k==1 || k== 0|| head == nullptr || head->next == nullptr){
            return head;
        }

        // 设置一个保护节点
        ListNode* dummy = new ListNode(0);
        ListNode* last = dummy;

        ListNode* nextGroup = nullptr;

        while(head) {
        	ListNode* endNode = getEnd(head,k);

        	// 说明剩余节点不够翻转了，返回
        	if(endNode==nullptr) {
        		break;
        	}

        	// 下个翻转链表的开始节点
        	nextGroup = endNode->next;

        	// 翻转这个链表的区间
        	reverseList(head, endNode);

        	last->next = endNode;
        	head->next = nextGroup;

        	last = head;
        	head = nextGroup;
        }

        return dummy->next;
	}

	// 判断链表是否还能否翻转 k 个
	ListNode* getEnd(ListNode* head, int k) {
		int index = 1;
		while (head!=nullptr) {
			head = head->next;
			if(++index==k){
				return head;
			}
		}

		return head;
	}

    ListNode* reverseList(ListNode* head, ListNode* end) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* next = head->next;
        head->next = NULL;

        ListNode* p;

        while (next != NULL && head != end) {
            p = next->next;
            next->next = head;
            head = next;
            next = p;
        }
        return head;
    }
};

int main(int argc, char *argv[]) {

    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);


    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;

    int k(2);

    Solution s;
    ListNode * res = s.reverseKGroup(n1, k);
    while(res!=nullptr) {
        cout<<res->val<<" ";
        res =res->next;
    }
    return 0;
}
