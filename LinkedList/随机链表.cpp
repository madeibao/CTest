



#include "iostream"
#include "bits/stdc++.h"

using namespace std;


class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        while(head)
        {
            tmp.push_back(head->val);
            cnt++;
            head=head->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int index=rand()%cnt;
        return tmp[index];
    }
    vector<int> tmp;
    int cnt=0;
};



int main(int argc, char* argv[]) {


	return 0;
}