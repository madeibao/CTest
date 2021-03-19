

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int v):val(v),next(nullptr) {}
};


/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pHead ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
      
        // 这里设置的是 p慢指针，q快指针。
        ListNode* p(pHead),* q(pHead);
        while(k&&q){
            q = q->next;
            k--;
        }
        if(k) return {};
        while(q){
            p = p->next;
            q = q->next;
        }
        return p;
    }
};


int main(int argc, char* argv[]) {

	  ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);


    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;


    int n =2;

    ListNode* res;
    Solution s;
    res= s.FindKthToTail(n1, n);
    while(res!=nullptr) {
    	cout<<res->val<<" ";
    	res = res->next;
    }

	return 0;
}
