
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct  TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    vector<vector<int>> level(TreeNode* root ) {
        queue<TreeNode*> queue;
        vector<vector<int>> res;
        if(root==nullptr) {
            return res;
        }

        queue.push(root);
        while(!queue.empty()) {

            int size = queue.size();
            //auto temp = vector<int>();

            vector<int> temp;
            for(int i=0;i<size;i++) {

            	// 弹出左面元素。
                TreeNode* node = queue.front();
                queue.pop();
                temp.push_back(node->val);
                if(node->left!=nullptr) {
                    queue.push(node->left);
                }
                if(node->right!=nullptr) {
                    queue.push(node->right);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main(int argc,  char* argv[]) {

    TreeNode* root = new TreeNode(1);
    TreeNode* l2 = new TreeNode(2);
    TreeNode* l3 = new TreeNode(3);

    root->left = l2;
    root->right = l3;

    vector<vector<int>> res;
    Solution s;
    res = s.level(root);
    for(auto a:res) {
        for(auto b:a) {
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}








