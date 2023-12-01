
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
    int deepestLeavesSum(TreeNode* root) {
        if(root == nullptr) return 0;
        vector<vector<int>> tree;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int levelSize = q.size();
            vector<int> cur;
            for(int i = 0; i < levelSize; i++) {
                TreeNode* curNode = q.front();
                q.pop();
                cur.push_back(curNode->val);
                if(curNode->left != nullptr)
                    q.push(curNode->left);
                if(curNode->right != nullptr)
                    q.push(curNode->right);
            }
            tree.push_back(cur);
        }
        int ans = 0;
        int n = tree.size()-1;
        int m = tree[n].size();
        for(int i = 0; i < m; i++) {
            ans = ans + tree[n][i];
        }
        return ans;
    }
};



int main(int argc,char** argv) {

	TreeNode* root = new TreeNode(1);
	TreeNode* l2 = new TreeNode(2);
	TreeNode* r2 = new TreeNode(3);

	root->left = l2;
	root->right = r2;

	Solution s;
	cout<<s.deepestLeavesSum(root)<<endl;

	return 0;
}
