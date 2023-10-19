
https://blog.csdn.net/ANoway/article/details/132403536


输入：
4 4
2 1 0 3
0 1 2 1
0 3 0 0
0 0 0 0


————————————————————————————————————————————————————————————————————————————————————————————————————————————

import copy
m, n = list(map(int, input().split()))
dp = [[0] * m for _ in range(n)]
for i in range(n):
    dp[i] = list(map(int, input().split()))
start = []
res = {}
for i in range(n):
    for j in range(m):
        if dp[i][j] == 2:
            start.append((i, j))
        elif dp[i][j] == 3:
            res[(i, j)] = 0

location = [(-1, 0), (1, 0), (0, 1), (0, -1)]


def dfs(a, x, y):
    global res, location
    if x < 0 or y < 0 or x == m or y == m or a[x][y] == 1:  # 这步包括剪枝和循环终止条件
        return
    else:  # 进入该模块的点表示可以移动
        for p in location:
            if a[x][y] == 3:
                res[(x, y)] += 1
            a[x][y] = 1  # 移动完成后，该点设置为1表示已经走过
            dfs(a, x + p[0], y + p[1])  # 调整x,y坐标继续移动
        return  # 所以遍历完成后，强制退出。一般在涉及需中途得到答案时，这步表示始终未找到答案


dp_0 = copy.deepcopy(dp)
for k in start:
    dfs(dp_0, k[0], k[1])
    dp_0 = dp

n = 0
for k in res:
    if res[k] == 2:
        n += 1
print(n)
