


#include<iostream>
#include<bits/stdc++.h>

using namespace std; //
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v):val(v),left(nullptr),right(nullptr){}
	TreeNode(int v, TreeNode* left, TreeNode* right):val(v),left(nullptr),right(nullptr){}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr&&q==nullptr) {
            return true;
        }

        if(!p||!q) {
            return false;
        }

        if(p->val!=q->val) {
            return false;
        }

        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};

int main() {
    
    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(3);
    root->left = left;
    root->right = right;


    TreeNode *roota = new TreeNode(1);
    TreeNode *lefta = new TreeNode(2);
    TreeNode *righta = new TreeNode(3);
    roota->left = lefta;
    roota->right = righta;

    Solution s2;
    cout<<s2.isSameTree(root,roota)<<endl;


    return 0;

}
