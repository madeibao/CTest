
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode *right;
	TreeNode(int v):val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     *
     * @param root TreeNode类 the root
     * @return bool布尔型vector
     */
    vector<bool> judgeIt(TreeNode* root) {
        // write code here
        if (!root)
            return {};
        vector<bool> ans(2);
        ans[0] = dfs(root);
        ans[1] = bfs(root);
        return ans;
    }

    // 判断是否为二叉搜索树的值。

    bool dfs(TreeNode *root) {
        if (!root)
            return true;
        if (root->left && root->left->val > root->val)
            return false;
        if (root->right && root->right->val < root->val)
            return false;
        return dfs(root->left) && dfs(root->right);
    }


    // 判断是否为平衡二叉树。
    bool bfs(TreeNode *root) {
        queue<TreeNode*> q;
        q.push(root);
        //int level = 0;
        while (!q.empty()) {
            int nums = q.size();
            //if (nums != pow(2, level++))  //这个是满二叉树的判断。。
            //    return false;
            for (int i = 0; i < nums; i++) {
                TreeNode *tmp = q.front();
                q.pop();
                if(!tmp->left && tmp->right)   //左空有右肯定不是完全二叉树。。
                    return false;
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
        }
        return true;
    }
};



int main(int argc, char**argv) {


	TreeNode* root =new TreeNode(2);
	TreeNode* l2 = new TreeNode(1);
	TreeNode* l3 = new TreeNode(3);

	root->left = l2;
	root->right = l3;
	Solution s;

    vector<bool> res;
    res =s.judgeIt(root);
    for(bool bb:res) {
        cout<<bb<<" ";
    }
	return 0;
}





