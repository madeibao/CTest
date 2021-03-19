
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode { //
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v),val(v),left(nullptr), right(nullptr){}
};

class Solution {
public:
    /**
     * 
     * @param root1 TreeNode类 
     * @param root2 TreeNode类 
     * @return bool布尔型
     */
    bool isSame(TreeNode *root1, TreeNode* root2){
        if (!root1 && !root2)return true;
        if (!root1 || !root2)return false;
        if (root1->val != root2->val) return false;
        if (isSame(root1->left, root2->left) && isSame(root1->right, root2->right))
            return true;
        else
            return false;
    }
    
    bool isContains(TreeNode* root1, TreeNode* root2) {
        // write code here
        if (!root1) return false;
        if (!root2) return true;
        if (isSame(root1, root2) || isContains(root1->left, root2) || isContains(root1->right, root2))
            return true;
        else
            return false;
    }
};


int main(int argc, char* argv[]) {

	TreeNode* root = new TreeNode(1);
	TreeNode* l2 = new TreeNode(2);
	TreeNode* r2 = new TreeNode(3);

	root->left = l2;
	root->right = r2;


	TreeNode* m = new TreeNode(1);
	TreeNode* m2 = new TreeNode(3);

	m->next = m2;

	Solution s;
	cout<<s.isContains(root, m);
	
	return 0;
}


