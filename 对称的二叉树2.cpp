
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
    bool isSymmetric(TreeNode* root) {
    	isMirror(root,root);
    }
	bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) { return true;  }
        if (t1 == nullptr || t2 == nullptr) { return false; }
        return (t1->val == t2->val)&&(isMirror(t1->right, t2->left))&& (isMirror(t1->left, t2->right));
    }
};

int main(int argc, char **argv) {

	TreeNode *head = new TreeNode(1);
	TreeNode *l2 = new TreeNode(2);
	TreeNode *r2 = new TreeNode(2);
    head->left = l2;
    head->right = r2;

	Solution s;
	cout<<s.isSymmetric(head)<<endl;
	return 0;
}
