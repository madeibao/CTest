


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        vector<int> va;
        while(head != nullptr){
            va.push_back(head->val);
            head = head->next;
        }

        res.resize(va.size(),0);
        stack<int> st;
        for(int i = va.size() - 1; i >= 0; --i){
            while(!st.empty() && st.top() <= va[i]){
                st.pop();
            }
            if(st.empty()){
                res[i] = 0;
            }
            else  {
				res[i] = st.top();
	            st.push(va[i]);
        	}
        }
        return res;
    }
};


