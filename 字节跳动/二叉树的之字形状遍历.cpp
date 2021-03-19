
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
	vector<vector<int>> levelTree(TreeNode* root) {

		vector<vector<int>> res;
		if(root==nullptr) {
			return res;
		}

        queue<TreeNode*> queue2;
        queue2.push(root);
        while(!queue2.empty()) {
            int size2 = queue2.size();
            vector<int> res2;
            for(int i=0;i<size2;i++) {
                TreeNode* node = queue2.front();
                queue2.pop();
                res2.push_back(node->val);
                if(node->left!=nullptr) {
                    queue2.push(node->left);
                }
                if(node->right!=nullptr) {
                    queue2.push(node->right);
                }
            }
            res.push_back(res2);
        }

        for(int i=0;i<res.size();i++) {
            if(i%2==1) {
                reverse(res[i].begin(),res[i].end());
            }
        }
        return res;
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
    res = s.levelTree(root);
    for(auto i:res) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }

	return 0;
}
