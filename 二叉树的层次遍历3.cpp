

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):left(nullptr),right(nullptr),val(x) {}
};

class Solution {
public:
	vector<vector<int>> level(TreeNode* root) {
		auto res = vector<vector<int>>();

		if(!root) {
			return res;
		}

		queue<TreeNode*> q;
		q.push(root);

		while(!q.empty()) {
			auto level = vector<int>();
			int size = q.size();
			for(int i = 0; i < size; ++i) {
				TreeNode* node = q.front();
				q.pop();
				level.push_back(node->val);
				if(node->left!=nullptr) {
					q.push(node->left);
				}
				if(node->right!=nullptr) {
					q.push(node->right);
				}
			}
			res.push_back(level);
		}
		return res;
	}
};

int main(int argc, char* argv[]) { //
    TreeNode* root = new TreeNode(1);
    TreeNode* l2 = new TreeNode(2);
    TreeNode* r2 = new TreeNode(3);

    root->left = l2;
    root->right = r2;

    vector<vector<int>> res;
    Solution s;
    res = s.level(root);
    for(auto a:res) {
        for(auto j:a) {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}


