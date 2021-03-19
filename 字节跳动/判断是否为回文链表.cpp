


#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct ListNode {

    int val;
    ListNode* next;
    ListNode(int v):val(v), next(nullptr){}

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
        vector<int> vec;
        ListNode* p = head;
        while (p) {
            vec.push_back(p->val);
            p = p->next;
        }
        int count = vec.size();
        for (int i=0; i<count/2; i++){
            if (vec[i] != vec[count-1-i]) {
                return false;
            }
        }
        return true;
    }
};


int main(int argc, char** argv) {

	ListNode* head = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(1);

	head->next = n2;
	n2->next = n3;
	n3->next = nullptr;

	Solution s;
	cout<<s.isPail(head)<<endl;

	return 0;
}
