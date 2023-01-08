
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
};


class Solution {

private:
    vector<string>res;
public:
    void trackpath(TreeNode* root,string path)
    {
        if(!root->left&&!root->right) {res.emplace_back(path);return;} //循环退出条件

        if(root->left) trackpath(root->left,path+"->"+to_string(root->left->val));
        if(root->right) trackpath(root->right,path+"->"+to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        trackpath(root,to_string(root->val));

        return res;
    }
};


int main(int argc, char* argv[]) {

    TreeNode* root = new TreeNode(1);
    TreeNode* l2 = new TreeNode(2);
    TreeNode* r2 = new TreeNode(3);

    root->left = l2;
    root->right = r2;

    Solution s;
    vector<string> res;
    res = s.binaryTreePaths(root);
    for(auto i:res) {
    	cout<<i<<endl;
    }
    return 0;
}



