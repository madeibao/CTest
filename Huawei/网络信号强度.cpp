#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Block {
    int x;
    int y;
    int d;
    Block(int xx, int yy, int dd) : x(xx), y(yy), d(dd) {}
};

int solveMethod(vector<vector<int>>& matrix, vector<int>& src,
                vector<int>& dst) {
    int m = matrix.size(), n = matrix[0].size();
    queue<Block> blocks;
    int x = src[0], y = src[1];
    blocks.push(Block(x, y, matrix[x][y]));
    while (!blocks.empty()) {
        Block block = blocks.front();
        blocks.pop();
        int x = block.x, y = block.y, d = block.d;
        if (d == -1) continue;
        for (auto& di : vector<vector<int>> {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
            int newX = x + di[0], newY = y + di[1];
            if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                int next = matrix[newX][newY];
                if (next == 0) {
                    matrix[newX][newY] = d - 1;
                    blocks.push(Block(newX, newY, d - 1));
                } else if (d > 2 && next != -1) {
                    blocks.push(Block(newX, newY, d - 1));
                }
            }
        }
    }
    return matrix[dst[0]][dst[1]];
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    vector<int> src(2), dst(2);
    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) {
            cin >> matrix[x][y];
            if (matrix[x][y] > 0) {
                src[0] = x;
                src[1] = y;
            }
        }
    }
    cin >> dst[0] >> dst[1];
    int res = solveMethod(matrix, src, dst);
    cout << res;
    return 0;
}


