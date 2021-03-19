
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

 struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int v):val(v),left(nullptr),right(nullptr){}
};


class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @param o1 int整型
     * @param o2 int整型
     * @return int整型
     */


    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        return help(root,o1,o2)->val;
    }


    TreeNode*help(TreeNode*root,int o1,int o2){
        if(!root||root->val==o1||root->val==o2)return root;

        TreeNode*left=help(root->left,o1,o2);
        TreeNode*right=help(root->right,o1,o2);

        if(left==nullptr)return right;
        if(right==nullptr)return left;

        return root;
    }
};


int main() {

    TreeNode* root = new TreeNode(1);
    TreeNode* h2 = new TreeNode(2);
    TreeNode* h3 = new TreeNode(3);

    root->left= h2;
    root->right =h3;

    Solution s;
    cout<<s.lowestCommonAncestor(root,2,3);

    return 0;
}

