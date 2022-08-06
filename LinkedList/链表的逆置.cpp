
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr) {}
};

class Solution {
    public:
        vector<int> reversePrint(ListNode* head) {
            vector<int> res;
            stack<int> sta;
            while(head) {
                sta.push(head->val);
                head= head->next;
            }
            while(!sta.empty()) {
                res.push_back(sta.top());
                sta.pop();
            }
            return res;
        }

};


int main() {

    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);

    n1->next = n2;
    n2->next = n3;
    n3->next = nullptr;
    vector<int> temp;
    Solution s;
    temp= s.reversePrint(n1);
    for(int i=0;i<temp.size();i++) {
        cout<<temp[i]<<endl;
    }
    return 0;
}



