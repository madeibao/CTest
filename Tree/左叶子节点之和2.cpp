

#include "iostream"
#include "bits/stdc++.h"

using namespace std; //

struct TreeNode {
    int val;
    TreeNode(int val) : val(val);
    TreeNode(int val, TreeNode* left,TreeNode* right):val(val), left(nullptr), right(nullptr){};
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }   

        if(root->left!=nullptr&&root->left->left==nullptr&&root->left->right==nullptr) {
            return root->left->val + sumOfLeftLeaves(root->right);
        }

        return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
    }
};



int main(int argc, char** argv) {


    return 0;
}