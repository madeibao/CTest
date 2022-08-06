
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int getDepth(TreeNode* root) {

        if(root==nullptr) {
            return 0;
        }
        if(root->left==nullptr&&root->right==nullptr) {
            return 1;
        }
        return max(getDepth(root->left), getDepth(root->right)) +1;
    }
};


int main(int argc, char* argv[]) {

    TreeNode* root = new TreeNode(1);
    TreeNode* l2 = new TreeNode(2);
    TreeNode* r2 = new TreeNode(3);

    root->left = l2;
    root->right = r2;

    Solution s;
    cout<<s.getDepth(root)<<endl;

    return 0;
}



