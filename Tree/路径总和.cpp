


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x),left(NULL),right(NULL){};
};

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    // 递归函数不需要返回值，因为我们要遍历整个树
    void traversal(TreeNode* cur, int count) {
        if (!cur->left && !cur->right && count == 0) { // 遇到了叶子节点切找到了和为sum的路径
            result.push_back(path);
            return;
        }

        if (!cur->left && !cur->right) return ; // 遇到叶子节点而没有找到合适的边，直接返回

        if (cur->left) { // 左 （空节点不遍历）
            path.push_back(cur->left->val);
            count -= cur->left->val;
            traversal(cur->left, count);    // 递归
            count += cur->left->val;        // 回溯
            path.pop_back();                // 回溯
        }
        if (cur->right) { // 右 （空节点不遍历）
            path.push_back(cur->right->val);
            count -= cur->right->val;
            traversal(cur->right, count);   // 递归
            count += cur->right->val;       // 回溯
            path.pop_back();                // 回溯
        }
        return ;
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        result.clear();
        path.clear();
        if (root == NULL) return result;
        path.push_back(root->val); // 把根节点放进路径
        traversal(root, sum - root->val);
        return result;
    }
};


int main(int argc, char **argv) {

    TreeNode* root = new TreeNode(5);
    TreeNode* l2 = new TreeNode(4);
    TreeNode* r2 = new TreeNode(8);

    TreeNode* m3a = new TreeNode(11);
    TreeNode* m3b = new TreeNode(13);
	TreeNode* m3c = new TreeNode(4);

	TreeNode* n3a = new TreeNode(7);
    TreeNode* n3b = new TreeNode(2);
	TreeNode* n3c = new TreeNode(5);
	TreeNode* n3d = new TreeNode(1);



	root->left = l2;
	root->right = r2;

	l2->left = m3a;

	m3a->left = n3a;
	m3a->right = n3b;


	r2->left = m3b;
	r2->right = m3c;


	m3c->left = n3c;
	m3c->right = n3d;

	Solution s2;

	vector<vector<int>> res;
	res = s2.pathSum(root, 22);

	for(auto a:res) {
        for(auto j:a) {
            cout<<j<<" ";
        }
        cout<<endl;
    }


	return 0;
}
