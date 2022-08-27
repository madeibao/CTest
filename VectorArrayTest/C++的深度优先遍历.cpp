

#include <cstdio>
#include <iostream>
using namespace std;

int matrix[110][110];
int s, m, n;
void dfs(int i, int j) {
  if (i >= m || j >= n) return;
  if (matrix[i][j] == 2) return;
  matrix[i][j] = 2;
  if (j < n - s && matrix[i][j + s]) {
    dfs(i, j + s);
  }
  if (i < m - s && matrix[i + s][j]) {
    dfs(i + s, j);
  }
  if (j >= s && matrix[i][j - s]) {
    dfs(i, j - s);
  }
  if (i >= s && matrix[i - s][j]) {
    dfs(i - s, j);
  }
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  cin >> s >> m >> n;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }
  dfs(0, 0);
  // 判断最后的一个是不是2,若是，就代表最终的结果值。
  cout << (matrix[m - 1][n - 1] == 2) << endl;
  return 0;
}
