


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
    vector<int> res;
public:
    void getTemp(TreeNode* root, int start) {
        if(root == nullptr) {
            return;
        }

        int tempval;
        tempval = start*10 + root->val;
        if(root->left==nullptr&&root->right==nullptr) {
            res.push_back(tempval);
            return;
        }

        if(root->left!=nullptr) {
            getTemp(root->left, tempval);
        }
        if(root->right!=nullptr) {
            getTemp(root->right, tempval);
        }
    }

    int sum() {
        int res2 = 0;
        for(int i:res) {
            res2+=i;
        }
        return res2;
    }

    int getSum2(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        getTemp(root, 0);
        return sum();
    }

};


int main(int argc, char* argv[]) {

    Solution s;
    TreeNode* root = new TreeNode(1);
    TreeNode* l2 = new TreeNode(2);
    TreeNode* l3 = new TreeNode(3);

    root->left = l2;
    root->right =l3;

    cout<<s.getSum2(root);

    return 0;
}
