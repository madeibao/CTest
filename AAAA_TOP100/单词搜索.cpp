
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

    	int m = board.size();
    	int n = board[0].size();

    	vector<vector<bool>> visited(m, vector<bool>(n,false));

    	for(int i=0;i<m;i++) {
    		for(int j=0;j<n;j++) {
    			if (dfs(board, visited, word, 0, i, j)) {
    			 	return true;
    			}
    		}
    	}
    	return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, const string& word, int index, int i, int j) {
        if(index==word.size()) {
            return true;
        }

        if(i>=board.size()||i<0||j>=board[0].size()||j<0||visited[i][j]==true||board[i][j]!=word[index]) {
            return false;
        }

        visited[i][j] = true;
        
        if(dfs(board,visited, word, index+1,i+1,j)||
           dfs(board,visited, word, index+1,i-1,j)||
           dfs(board,visited, word, index+1,i,j+1)||
           dfs(board,visited, word, index+1,i,j-1)) {
               return true;
        }
        visited[i][j] = false;

        return false;
    }

};

int main() {

	vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	Solution s2;
	string word = "ABCCED";

	cout<<s2.exist(board, word)<<endl;
	return 0;
}
