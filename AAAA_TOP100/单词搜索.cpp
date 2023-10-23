
// 单词搜索

#include<iostream>
#include<bits/stdc++.h>
using  namespace std;


//dfs
class Solution {
public:
    bool helper(vector<vector<char>>& board, string& word, int i,int j,int length){
        if(i>=board.size()||j>=board[0].size()||i<0||j<0||length>=word.size()||word[length]!=board[i][j]){
            return false;
        }
        if(length==word.size()-1&&word[length]==board[i][j]){
            return true;
        }
        char temp=board[i][j];
        board[i][j]='-';  //找到之后随便修改一个值
        bool flag=helper(board,word,i,j+1,length+1)||helper(board,word,i,j-1,length+1)||helper(board,word,i+1,j,length+1)||helper(board,word,i-1,j,length+1);
        board[i][j]=temp;//遍历之后再给恢复
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(unsigned int i=0;i<board.size();i++){
            for(unsigned int j=0;j<board[0].size();j++){
                    if(helper(board,word,i,j,0))
                        return true;
            }
        }
        return false;
    }
};

int main(int argc, char** argv) {
	vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	string word = "ABCCED";

	Solution s;
	cout << s.exist(board,word) << endl;
	return 0;
}
