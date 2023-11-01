


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> help;
        inorder(root,help);
        for(int i=1;i<help.size();i++){
            if(help[i]<=help[i-1]) return false;
        }
        return true;
    }
    void inorder(TreeNode* root,vector<int>& ans){
        if(root==nullptr) return ;
        inorder(root->left,ans);
        ans.emplace_back(root->val);
        inorder(root->right,ans);
    }
};

int main(int argc, char** argv) {

	Solution s;

	TreeNode *root = new TreeNode(2);
    TreeNode *left = new TreeNode(1);
    TreeNode *right = new TreeNode(4);
    root->left = left;
    root->right = right;

    cout<<s.isValidBST(root)<<endl;
	return 0;
}
