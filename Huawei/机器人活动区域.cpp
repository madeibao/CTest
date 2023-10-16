
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int m, n;

void dfs(int i, int j, vector<vector<int>> v,vector<vector<int>> &rd, vector<vector<int>> &rd2,int &tmp) {
	int a = v[i][j];
	rd[i][j]++; 
	rd2[i][j]++;
	tmp++;
	if (i + 1 < m && rd[i + 1][j]==0 && abs(v[i+1][j] - a) <= 1)
		dfs(i+1, j, v, rd,rd2,tmp);
	if (i - 1 >= 0 && rd[i - 1][j] == 0 && abs(v[i-1][j] - a) <= 1)
		dfs(i-1, j, v, rd,rd2,tmp);
	if (j + 1 < n && rd[i][j + 1] == 0 && abs(v[i][j+1] - a) <= 1)
		dfs(i, j+1, v, rd,rd2, tmp);
	if (j - 1 >= 0 && rd[i][j - 1] == 0 && abs(v[i][j-1] - a) <= 1)
		dfs(i, j-1, v, rd,rd2, tmp);
}

int main() {
	int count=0;
	cin >> m >> n;
	vector<vector<int>>v(m,vector<int>(n));
	vector<vector<int>>rd(m, vector<int>(n, 0));
	vector<vector<int>>rd2(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (rd2[i][j] == 0) {
				vector<vector<int>>rd(m, vector<int>(n, 0));
				int tmp = 0;
				dfs(i, j, v, rd,rd2, tmp);
				count = max(count, tmp);
			}
		}
	}
	cout << count;
}



