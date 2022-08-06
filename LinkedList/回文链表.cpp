
//回文链表。

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head)return true;

        vector<int>nums;
        while(head){
            nums.push_back(head->val);
            head=head->next;
        }

        // 通过一个列表来存储其中的值。
        int left=0,right=nums.size()-1;
        while(left<right){
            if(nums[left]!=nums[right])return false;
            left++;right--;
        }
        return true;
    }
};


int main(int argc, char** argv) {

    ListNode *n1 =new ListNode(1);
    ListNode *n2 =new ListNode(2);
    ListNode *n3 =new ListNode(2);
    ListNode *n4 =new ListNode(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = nullptr;
    Solution s;
    cout<<s.isPalindrome(n1)<<endl;
    return 0; //
}

