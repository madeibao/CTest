


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
		vector<string> generate(TreeNode* node) {

			vector<string> res;
			if(node==nullptr) {
				return res;
			}
			helper("",res, node);
			return res;
		}

		void helper(string str, vector<string>& vec, TreeNode* root) {

            if(str=="") {
                str = to_string(root->val);
            }
            else {
                str = str + "->" + to_string(root->val);
            }
			if(!root->left&&!root->right) {
				vec.push_back(str);
			}

            if(root->left) {
                helper(str,vec, root->left);
            }

            if(root->right) {
                helper(str,vec, root->right);
            }

		}
};



int main(int argc, char* argv[]) {

	TreeNode *head = new TreeNode(1);
	TreeNode *l2 = new TreeNode(2);
	TreeNode *r2 = new TreeNode(3);
    head->left = l2;
    head->right = r2;

    Solution s;
    vector<string> res;
    res = s.generate(head);

    for(auto i:res) {
    	cout<<i<<" "<<endl;
    }

	return 0;
}
