

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
    int getSum(TreeNode* root, int tempval) {

        int sum=0;
        if(root==nullptr) {
            return 0;
        }
        sum = tempval*10+ root->val;
        if(root->left==nullptr&&root->right==nullptr) {
            return sum;
        }
        return getSum(root->left, sum)+ getSum(root->right,  sum);
    }

    int getSum(TreeNode* root) {
        return getSum(root, 0);
    }

};


int main(int argc, char* argv[]) {

    Solution s;
    TreeNode* root = new TreeNode(1);
    TreeNode* l2 = new TreeNode(2);
    TreeNode* l3 = new TreeNode(3);

    root->left = l2;
    root->right =l3;

    cout<<s.getSum(root);

    return 0;
}
