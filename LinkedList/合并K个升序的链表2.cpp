
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ans;
        for(int i=0;i<lists.size();i++){
            ListNode* cur=lists[i];
            while(cur!=NULL){
                ans.push_back(cur->val);
                cur=cur->next;
            }   
        }
        sort(ans.begin(),ans.end());
        ListNode* head=new ListNode(-1);//哑结点
        ListNode* cur=head;//移动指针
        for(int i=0;i<ans.size();i++){
            ListNode* newNode=new ListNode(ans[i]);
            cur->next=newNode;
            cur=newNode;
        }
        return head->next;
    }
};

