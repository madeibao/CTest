







#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==nullptr) {
            return root;
        }
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};


void preOrder(TreeNode* root) {
    if(root==nullptr) {
        return;
    }
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}


int main() {
    Solution s;
    TreeNode* root= new TreeNode(1);
    TreeNode* l2 = new TreeNode(2);
    TreeNode* l3 = new TreeNode(3);
    root->left= l2;
    root->right = l3;

    TreeNode* res= s.mirrorTree(root);
    preOrder(res);
    return 0;
}
