
/**
5
1 2 3 4 5
6 
7 8 9 10 11 12


输出：
1 2 3 4 5 7 8 9 10 11 12

*/

#include<bits/stdc++.h>
#include<iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x):val(x), next(NULL){}
};

ListNode* input(void) {
    int n, val;

    ListNode* phead = new ListNode();
    ListNode* cur = phead;

    cin>>n;

    for(int i=1;i<=n;i++) {
        cin>>val;

        // 如果是第一个元素的值。
        if(i==1) {
            cur->val = val;
            cur->next =NULL;
        }
        else {

            // 声明一个链表的节点并且要进行赋值。
            ListNode* newHead = new ListNode();
            newHead->val = val;
            newHead->next =NULL;

            cur->next = newHead;
            cur = newHead;
        }
    }
    return phead;

}

ListNode* mergeListNode(ListNode* head1, ListNode* head2) {
    ListNode* res = new ListNode();

    ListNode* p1 = head1;
    ListNode* p2 = head2;

    ListNode* p3 = res;

    while (p1 != NULL&&p2 != NULL) {
        if(p1->val <p2->val) {
            p3->next = p1;
            p3 =p1;
            p1 =p1->next;
        }
        else {
            p2->next = p2;
            p3 = p2;
            p2 =p2->next;
        }
    }

    while(p2!=NULL) {
        p3->next = p2;
        p3 =p2;
        p2 =p2->next;
    }

    while(p1!=NULL){
        p3->next = p1;
        p3=p1;
        p1=p1->next;
    }
    return res->next;
}

void printListNode(ListNode* head) {

    while(head!=NULL) {
        cout<<head->val<<"->";
        head = head->next;
    }
}



int main(int argc, char** argv) {
    ListNode* head1 = input();
    ListNode* head2 = input();
    ListNode* head3 = mergeListNode(head1, head2);
    printListNode(head3);
    return 0;
}






