




#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(){}
	TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    /**
     *
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    vector<int> pre_tree;
    vector<int> mid_tree;
    vector<int> post_tree;

    vector<vector<int>> threeOrders(TreeNode* root) {
        // write code here
        if(root!=nullptr){
            preorder(root);
            midorder(root);
            postorder(root);

        }
        vector<vector<int>>res={pre_tree,mid_tree,post_tree};
        return res;
    }

    void preorder(TreeNode *root) {
        if(root==NULL){
            return;
        }
        pre_tree.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

    void midorder(TreeNode *root) {
        if(root==NULL){
            return;
        }
            midorder(root->left);
            mid_tree.push_back(root->val);
            midorder(root->right);
    }

    void postorder(TreeNode *root) {
        if(root==NULL){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        post_tree.push_back(root->val);
    }
};



int main(int argc,char **argv) {


	TreeNode* root = new TreeNode(1);
	TreeNode* r2 = new TreeNode(2);
	TreeNode* r3 = new TreeNode(3);

	root->left = r2;
	root->right = r3;

	vector<vector<int>> res;
	Solution s;
	res = s.threeOrders(root);

	for(auto r:res) {
		for(auto j:r) {
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}
