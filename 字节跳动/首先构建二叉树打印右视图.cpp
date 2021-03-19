

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct TreeNode {

	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v):val(v),left(nullptr),right(nullptr){}
};
//先构建出二叉树，再打印出右视图


class Solution {
public:
    vector<int> ans;
    vector<int> solve(vector<int> &preorder, vector<int> &inorder) {
        int presize = preorder.size();
        int insize = inorder.size();
        if (presize != insize || presize == 0 || insize == 0)
            return ans;
        auto head = ReconstructTree(preorder, inorder, 0, presize - 1, 0, insize - 1);
        rightTree(head);
        return ans;
    }

    
    void rightTree(TreeNode *head) {

        // 首先构建一个队列的值。
        queue<TreeNode *> q;
        q.push(head);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto tmp = q.front();
                q.pop();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);

                // 如果等于值队列值减去1
                if (i == size - 1) ans.push_back(tmp->val);
            }
        }
    }


    TreeNode *ReconstructTree(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int il, int ir) {
        auto *root = new TreeNode(preorder[pl]);
        if (pl == pr) return root;
        int index = 0;
        for (int i = il; i <= ir; i++) {
            if (inorder[i] == preorder[pl]) {
                index = i;
                break;
            }
        }
        int ltreelen = index - il;
        int rtreelen = ir - index;
        if (ltreelen > 0) root->left = ReconstructTree(preorder, inorder, pl + 1, pl + ltreelen, il, index - 1);
        if (rtreelen > 0) root->right = ReconstructTree(preorder, inorder, pl + 1 + ltreelen, pr, index + 1, ir);
        return root;
    }
};


int main(int argc, char** argv) { //

	vector<int> list2 = {1,2,4,5,3};
	vector<int> list3 = {4,2,5,1,3};

	Solution s;
	vector<int> res = s.solve(list2, list3);
	for(int i:res) {
		cout<<i<<" ";
	}

	return 0;
}
