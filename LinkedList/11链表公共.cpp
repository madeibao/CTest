


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// Define the structure for a linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main() {


    // 生成
    ListNode* current = head;
    for(int i=2;i<=10;i++){
        ListNode* newNode = new ListNode(i);
        current->next = newNode;
        current = current->next;
    }

    newCurrent = newHead;
    while (newCurrent != NULL) {
        cout << newCurrent->val << " ";
        newCurrent = newCurrent->next;
    }
    cout << endl;
    
    // 

    return 0;
}