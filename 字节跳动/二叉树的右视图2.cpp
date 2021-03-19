
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr) {}
};


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            
            int len = que.size();
            for (int i = 0; i < len; i++) {
                auto q = que.front();
                que.pop();
                if (i == len - 1) {
                    ans.push_back(q->val);
                }
                if (q->left != nullptr) {
                    que.push(q->left);
                }
                if (q->right != nullptr) {
                    que.push(q->right);
                }
            }
        }
        return ans;
    }
};


int main(int argc, char* argv[])  {


    TreeNode* head = new TreeNode(1);
    TreeNode* h2=  new TreeNode(2);
    TreeNode* h3 = new TreeNode(3);
    head->left = h2;
    head->right = h3;

    Solution s;
    vector<int> res;
    res = s.rightSideView(head);
    for(int i:res) {
        cout<<i<<" ";
    }

    return 0;
}


