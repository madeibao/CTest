

// 二叉树的第二小的节点
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // root->val = min(root->left->val, root->right->val);
    // BFS + 队列 + 迭代
    // 特点： 根节点一定是最小的，但是根节点的孩子节点不一定是第二小的
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> tmp;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto node = q.front(); q.pop();
                tmp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        sort(tmp.begin(), tmp.end());
        for(auto x : tmp)
            if(x != root->val)
                return x;
        return -1;
    }
};


int main() {

    TreeNode* root= new TreeNode(2);
    TreeNode* a2 = new TreeNode(2);
    TreeNode* a3 = new TreeNode(5);
    TreeNode* b2 = new TreeNode(5);
    TreeNode* b3 = new TreeNode(7);

    root->left = a2;
    root->right = a3;

    a3->left = b2;
    a3->right = b3;

    Solution s2;
    cout<<s2.findSecondMinimumValue(root)<<endl;
    return 0;
}
