
#include<iostream>
#include<bits/stdc++.h>
using namespace std; //

 struct TreeNode {
	int val;
 	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param pRoot TreeNode类
     * @return TreeNode类
     */
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here

        if(pRoot==nullptr) {
            return nullptr;
        }

        if(pRoot->left==nullptr&&pRoot->right==nullptr) {
            return pRoot;
        }
        TreeNode* temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;

        Mirror(pRoot->left);
        Mirror(pRoot->right);
        return pRoot;
    }
};


void preOrder(TreeNode* root) {

	if(root==nullptr) {
		return;
	}

	cout<<root->val<< " ";
	preOrder(root->left);
	preOrder(root->right);
}

int main(int argc, char* argv[]) {

	TreeNode* root = new TreeNode(1);
	TreeNode* h2 =new TreeNode(2);
	TreeNode* h3 = new TreeNode(3);

	root->left = h2;
	root->right = h3;

	TreeNode* res;
	Solution s;
	res= s.Mirror(root);
	preOrder(res);

	return 0;
}




