


#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v):val(v),left(nullptr),right(nullptr){}
	TreeNode(int v, TreeNode* left, TreeNode* right):val(v),left(nullptr),right(nullptr){}
};


class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) {
            return 0;
        }

        return countNodes(root->left)+countNodes(root->right)+1;
    }
};

int main(int argc, char** argv) {

    TreeNode* root = new TreeNode(1);
    TreeNode* l2 = new TreeNode(2);
    TreeNode* r2 = new TreeNode(3);

    root->left = l2;
    root->right = r2;

    vector<vector<int>> res;
    Solution s;

    cout<<s.countNodes(root)<<endl;
	return 0;
}