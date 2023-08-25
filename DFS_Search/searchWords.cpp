
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (dfs(board, visited, word, 0, i, j)) return true;
            }
        }

        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, const string& word, int str_idx, int i, int j) {
        if (str_idx == word.size()) {
            return true;
        }
        // 越界、被访问过、当前位置的字符不是word对应位置的字符
        if (i >= board.size() || i < 0 ||
            j >= board[0].size() || j < 0 ||
            visited[i][j] == true || board[i][j] != word[str_idx]) {
                return false;
        }

        visited[i][j] = true;
        if (dfs(board, visited, word, str_idx + 1, i + 1, j) ||
            dfs(board, visited, word, str_idx + 1, i - 1, j) ||
            dfs(board, visited, word, str_idx + 1, i, j + 1) ||
            dfs(board, visited, word, str_idx + 1, i, j - 1)) {
                return true;
            }
        visited[i][j] = false;
        return false;
    }
};


int main(int argc, char** argv) {

	vector<vector<char>> board = {{'A','B','C','E',},{'S','F','C','S'},{'A','D','E','E'}};
	string word = "SEE";
	Solution s2;
	cout<<s2.exist(board,word)<<endl;
	return 0;
}
