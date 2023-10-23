
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
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};


int main(int argc, char** argv) {

	TreeNode *head = new TreeNode(1);
	TreeNode *l2 = new TreeNode(2);
	TreeNode *r2 = new TreeNode(3);
    head->left = l2;
    head->right = r2;

    Solution s;
    vector<int> res;
    res = s.inorderTraversal(head);
    for(int i :res) {	
    	cout << i<<" "<<endl;
    }
}