
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int x):val(x),next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(nullptr) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        helper(root);
        return res;
    }

private:
    vector<int> res;
    void helper(TreeNode* root) {
        if(!root) {
            return;
        }

        res.push_back(root->val);
        inorderTraversal(root->left);
        inorderTraversal(root->right);
        
    }
};


int main(int argc, char* argv[]) { //
    TreeNode* root = new TreeNode(1);
    TreeNode* l2 = new TreeNode(2);
    TreeNode* r2 = new TreeNode(3);

    root->left = l2;
    root->right = r2;

    vector<int> res;
    Solution s;
    res = s.inorderTraversal(root);
    for(auto a:res) {
        for(auto j:a) {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}